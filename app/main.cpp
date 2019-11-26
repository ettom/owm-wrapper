#include <iostream>
#include <sstream>
#include <string>

#include "CLI11.hpp"

#include "core.h"
#include "filesystem.h"
#include "helpers.h"
#include "temperature_unit.h"
#include "weather_getter.h"
#include "weather_reporter.h"

int main(int argc, char* argv[])
{
	CLI::App app {"Generate daily weather reports using the OpenWeatherMap API."};

	std::string input_filename;
	std::string output_filename;
	TemperatureUnit::Unit unit = TemperatureUnit::CELSIUS;
	std::vector<std::string> cities;

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

	CLI11_PARSE(app, argc, argv);

	if (!input_filename.empty()) {
		cities = read_file(input_filename);
	}

	const WeatherGetter getter;
	QueryParameters q;
	q.timezone_offset = get_system_timezone_offset();
	q.temperature_unit = unit;

	json result = json::array();

	for (const auto& city : cities) {
		q.city = city;
		try {
			Forecast f = get_forecast(q, getter);
			result.push_back(f);
		} catch (const InvalidCityException& e) {
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << result.dump(4) << std::endl;
	if (!output_filename.empty()) {
		write_json_to_file(output_filename, result);
	}

	return EXIT_SUCCESS;
}
