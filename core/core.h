#pragma once
#include <iostream>
#include <string>
#include <vector>

struct QueryParameters {
	std::string city;
	std::string url;
	std::string api_key = "68f5814e37a11ad9d5f9c3b98680c2df";
	std::string lang = "en";
	std::string unit = "metric";
};

struct Report {
	std::string date;
	double temperature;
	double humidity;
	double pressure;

	friend void PrintTo(const Report& report, std::ostream* os)
	{
		*os << "  date = " << report.date << std::endl
		    << "\t\ttemperature = " << report.temperature << std::endl
		    << "\t\thumidity = " << report.humidity << std::endl
		    << "\t\tpressure = " << report.pressure << std::endl;
	}
};

struct Forecast {
	std::string city;
	std::string coordinate;
	std::string temperature_unit;
	Report current_weather;
	std::vector<Report> forecasts;
};
