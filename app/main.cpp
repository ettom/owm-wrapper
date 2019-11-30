#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "CLI11.hpp"

#include "core.h"
#include "helpers.h"
#include "reader_writer.h"
#include "temperature_unit.h"
#include "weather_getter.h"
#include "weather_reporter.h"

int main(int argc, char* argv[])
{
	CLI::App app {"Generate daily weather reports using the OpenWeatherMap API."};

	std::string input_filename;
	std::string output_filename;
	TemperatureUnit::Unit unit {TemperatureUnit::CELSIUS};
	std::vector<std::string> cities;
	bool logging_on = false;

	auto input = app.add_option_group("input", "Cities to generate reports for");

	input->add_option("-i, --input", input_filename,
			 "Path to a file containing the city names for "
			 "which reports are to be generated\n"
			 "Each city name must be on a separate line")
	    ->check(CLI::ExistingFile);

	input->add_option("-c, --city", cities, "List of city names");
	input->require_option(1);

	app.add_option("-o,--output", output_filename,
		       "Where to write the weather reports\n"
		       "If no output path is provided, result will be written to stdout");

	app.add_option("-u,--unit", unit, "Temperature unit, defaults to celsius")
	    ->transform(CLI::CheckedTransformer(TemperatureUnit::make_unit_displayname_pairs(), CLI::ignore_case));

	app.add_flag("-l,--log", logging_on, "Write API responses to owm-wrapper.log");

	CLI11_PARSE(app, argc, argv);

	WeatherGetter getter {logging_on};

	QueryParameters q;
	q.timezone_offset = get_system_timezone_offset();
	q.temperature_unit = unit;

	ReaderWriter rw;
	rw.input_filename = input_filename;
	rw.output_filename = output_filename;

	if (!input_filename.empty()) {
		cities = rw.read_file();
	}

	try {
		const json result = make_forecasts(q, getter, cities);
		if (!output_filename.empty()) {
			rw.write_json_to_file(result);
		} else {
			std::cout << result.dump(4) << std::endl;
		}
	} catch (const std::runtime_error& e) {
		std::cout << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
