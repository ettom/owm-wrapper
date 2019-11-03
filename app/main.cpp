#include <iostream>
#include <sstream>
#include <string>

#include "core.h"
#include "helpers.h"
#include "weather_getter.h"
#include "weather_reporter.h"
#include "filesystem.h"
#include "temperature_unit.h"

int main(int argc, char *argv[])
{
	if (argc < 2) {
		std::cerr << "Pass a file with city names as an argument. Output will be written to output.json" << std::endl;
		return EXIT_FAILURE;
	}

	std::vector<std::string> lines = read_file(argv[1]);

	WeatherGetter getter;
	QueryParameters q;
	q.timezone_offset = get_system_timezone_offset();
	q.temperature_unit = TemperatureUnit::CELSIUS;

	json result = json::array();

	for (auto line : lines) {
		q.city = line;
		result.push_back(get_forecast(q, getter));
	}

	std::cout << result.dump(4) << std::endl;
	write_json_to_file("output.json", result);
	return EXIT_SUCCESS;
}
