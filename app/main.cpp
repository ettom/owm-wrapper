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
	CLI::App app { "Generate daily weather reports using the OpenWeatherMap API." };
	std::string input_filename;
	std::string output_filename;
	TemperatureUnit::Unit unit = TemperatureUnit::CELSIUS;
	app.add_option("-i,--input", input_filename,
		       "Path to the input file containing the city names for "
		       "which reports are to be generated")
	    ->required()
	    ->check(CLI::ExistingFile);

	app.add_option("-o,--output", output_filename,
		       "Where to write the weather reports. If no output path "
		       "is provided, result will be written to stdout");

	using namespace TemperatureUnit;
	std::array<std::pair<Unit, const char*>, SIZE_OF_ENUM> arr = TemperatureUnit::make_unit_displayname_pairs();
	std::vector<std::pair<Unit, const char*>> v(std::begin(arr), std::end(arr));

	for (auto i : v) {
		std::cout << i.first << std::endl;
		std::cout << i.second << std::endl;
	}

	app.add_option("-u,--unit", unit, "Temperature unit")->transform(CLI::Transformer(v));

	CLI11_PARSE(app, argc, argv);
	std::cout << unit << std::endl;

	const std::vector<std::string> lines = read_file(input_filename);

	const WeatherGetter getter;
	QueryParameters q;
	q.timezone_offset = get_system_timezone_offset();
	q.temperature_unit = unit;

	json result = json::array();

	for (const auto& line : lines) {
		q.city = line;
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
