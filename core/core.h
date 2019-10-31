#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

struct QueryParameters {
	size_t days = 3;
	std::string city;
	std::string url;
	std::string api_key = "68f5814e37a11ad9d5f9c3b98680c2df";
	std::string lang = "en";
	std::string temperature_unit = "Celsius";
};

struct Report {
	const char* date_format = "%d.%m.%Y";
	uint32_t datetime;
	std::string date;

	double temperature;
	double humidity;
	double pressure;

	double at(const std::string& key) const
	{
		if (key == "temperature") {
			return this->temperature;
		} else if (key == "humidity") {
			return this->humidity;
		} else if (key == "pressure") {
			return this->pressure;
		}

		throw std::runtime_error("No such member in Report struct!");
	}

	friend void PrintTo(const Report& report, std::ostream* os)
	{
		*os << "  datetime = " << report.datetime << std::endl
		    << "\t\tdate = " << report.date << std::endl
		    << "\t\ttemperature = " << report.temperature << std::endl
		    << "\t\thumidity = " << report.humidity << std::endl
		    << "\t\tpressure = " << report.pressure << std::endl;
	}
};


using Reports_by_day = std::vector<std::vector<Report>>;

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
