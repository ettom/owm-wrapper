#pragma once
#include <ctime>
#include <string>
#include <vector>

#include <nlohmann/json.hpp>

#include "temperature_unit.h"

inline const std::string OWM_INVALID_CITY_RESPONSE {"city not found"};
inline const std::string OWM_TODAY_BASE_URL {"http://api.openweathermap.org/data/2.5/weather"};
inline const std::string OWM_5_DAY_FORECAST_BASE_URL {"http://api.openweathermap.org/data/2.5/forecast"};
inline const size_t REPORTS_PER_DAY_IN_FORECAST {8};

inline const std::string LOG_FILENAME {"owm-wrapper.log"};

struct QueryParameters {
	std::string city;

	long timezone_offset;
	TemperatureUnit::Unit temperature_unit;

	std::string url;
	std::string api_key {"68f5814e37a11ad9d5f9c3b98680c2df"};
	std::string lang {"en"};

	size_t days {3};
	size_t decimal_points {2};
};

struct Report {
	const char* date_format = "%d.%m.%Y";
	time_t datetime;
	std::string date;

	double temperature;
	double humidity;
	double pressure;

	// these behave like free functions due to ADL
	friend void to_json(nlohmann::json& j, const Report& r)
	{
		j = nlohmann::json {{"datetime", r.datetime},
				    {"date", r.date},
				    {"temperature", r.temperature},
				    {"humidity", r.humidity},
				    {"pressure", r.pressure}};
	}

	friend void from_json(const nlohmann::json& j, Report& r)
	{
		j.at("datetime").get_to(r.datetime);
		j.at("date").get_to(r.date);
		j.at("temperature").get_to(r.temperature);
		j.at("humidity").get_to(r.humidity);
		j.at("pressure").get_to(r.pressure);
	}

	friend bool operator==(const Report& report1, const Report& report2)
	{
		nlohmann::json j1 = report1;
		nlohmann::json j2 = report2;
		return j1 == j2;
	}
};

using ReportsByDay = std::vector<std::vector<Report>>;

struct Forecast {
	std::string city;
	std::string coordinates;
	TemperatureUnit::Unit temperature_unit;
	Report current_weather;
	std::vector<Report> reports;

	friend void to_json(nlohmann::json& j, const Forecast& f)
	{
		j = nlohmann::json {{"city", f.city},
				    {"coordinates", f.coordinates},
				    {"temperature_unit", TemperatureUnit::for_display[f.temperature_unit]},
				    {"current_weather", f.current_weather},
				    {"reports", f.reports}};
	}

	friend void from_json(const nlohmann::json& j, Forecast& f)
	{
		auto tmp = j.at("temperature_unit").get<std::string>();
		f.temperature_unit = TemperatureUnit::match_display_name_to_unit(tmp);

		j.at("city").get_to(f.city);
		j.at("coordinates").get_to(f.coordinates);
		j.at("current_weather").get_to(f.current_weather);
		j.at("reports").get_to(f.reports);
	}

	friend bool operator==(const Forecast& forecast1, const Forecast& forecast2)
	{
		nlohmann::json j1 = forecast1;
		nlohmann::json j2 = forecast2;
		return j1 == j2;
	}
};

struct WeatherData {
	nlohmann::json current_weather_data;
	nlohmann::json forecast_data;
};
