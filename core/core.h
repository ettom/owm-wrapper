#pragma once
#include <iostream>
#include <string>
#include <vector>

#include <nlohmann/json.hpp>
using json = nlohmann::json;
using Forecasts_data = std::map<std::string, std::vector<json>>;

struct QueryParameters {
	std::string city;
	std::string url;
	std::string api_key = "68f5814e37a11ad9d5f9c3b98680c2df";
	std::string lang = "en";
	std::string temperature_unit = "Celsius";
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
	std::string coordinates;
	std::string temperature_unit;
	Report current_weather;
	std::vector<Report> reports;
};

struct WeatherData {
	json current_weather_data;
	json forecast_data;

	friend void PrintTo(const WeatherData& wd, std::ostream* os)
	{
		*os << "  current_weather_data = " << wd.current_weather_data.dump(4) << std::endl
			<< "\t\tforecast_data = " << wd.forecast_data.dump(4) << std::endl;
	}
};
