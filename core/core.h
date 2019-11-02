#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <cstdint>

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
	time_t datetime;
	std::string date;

	double temperature;
	double humidity;
	double pressure;

	friend void to_json(json& j, const Report& r)
	{
		j = json {{"datetime", r.datetime},
			{"date", r.date},
			{"temperature", r.temperature},
			{"humidity", r.humidity},
			{"pressure", r.pressure}};
	}

	friend void from_json(const json& j, Report& r)
	{
		j.at("datetime").get_to(r.datetime);
		j.at("date").get_to(r.date);
		j.at("temperature").get_to(r.temperature);
		j.at("humidity").get_to(r.humidity);
		j.at("pressure").get_to(r.pressure);
	}

	friend void PrintTo(const Report& report, std::ostream* os)
	{
		json j = report;
		*os << std::setw(4) << j;
	}
};


using Reports_by_day = std::vector<std::vector<Report>>;

struct Forecast {
	std::string city;
	std::string coordinates;
	std::string temperature_unit;
	Report current_weather;
	std::vector<Report> reports;

	friend void to_json(json& j, const Forecast& f)
	{
		j = json {{"city", f.city},
			{"coordinates", f.coordinates},
			{"temperature_unit", f.temperature_unit},
			{"current_weather", f.current_weather},
			{"reports", f.reports}};
	}

	friend void from_json(const json& j, Forecast& f)
	{
		j.at("city").get_to(f.city);
		j.at("coordinates").get_to(f.coordinates);
		j.at("temperature_unit").get_to(f.temperature_unit);
		j.at("current_weather").get_to(f.current_weather);
		j.at("reports").get_to(f.reports);

	}
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
