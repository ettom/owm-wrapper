#include "report_parser.h"

std::string get_city(const json& response)
{
	if (response.count("name")) {
		return response["name"].get<std::string>();
	} else if (response.count("city")) {
		return response["city"]["name"].get<std::string>();
	}
	return "";
}

void check_if_invalid_city(const std::string& city, const json& response)
{
	if (get_city(response) != city) {
		throw InvalidCityException();
	}
}

std::string get_coordinates(const json& response)
{
	std::string result;
	json coordinates = (response["coord"].is_null()) ? response["city"]["coord"] : response["coord"];
	result = coordinates["lat"].dump() + "," + coordinates["lon"].dump();
	return result;
}

Forecast get_main_data(const WeatherData& wd)
{
	Forecast f {};
	f.coordinates = get_coordinates(wd.current_weather_data);
	f.city = get_city(wd.current_weather_data);
	return f;
}


size_t find_report_by_date(const Reports_by_day& reports, const std::string& date)
{
	for (size_t i = 0; i < reports.size(); i++) {
		for (auto r : reports.at(i)) {
			if (r.date == date) {
				return i;
			}
		}
	}

	return std::string::npos;
}

Reports_by_day remove_partial_days(const Reports_by_day& input)
{
	Reports_by_day result;
	auto pred = [](auto & x) {
		return x.size() == 8;
	};

	std::copy_if(input.begin(), input.end(), std::back_inserter(result), pred);
	return result;
}

Reports_by_day group_by_date(const std::vector<Report>& reports)
{
	Reports_by_day result;
	for (auto r : reports) {
		size_t to_insert = find_report_by_date(result, r.date);
		if (to_insert == std::string::npos) {
			result.push_back(std::vector<Report> {r});
		} else {
			result.at(to_insert).push_back(r);
		}
	}

	return result;
}

Reports_by_day parse_forecast_data(const json& response, time_t timezone_offset)
{
	std::vector<Report> result;

	for (auto& [key, value] : response["list"].items()) {
		Report r {};
		r.datetime = value["dt"].get<time_t>() + timezone_offset;
		r.date = unix_time_to_string(r.datetime, r.date_format);
		r.temperature = value["main"]["temp"];
		r.humidity = value["main"]["humidity"];
		r.pressure = value["main"]["pressure"];
		result.push_back(r);
	}

	return group_by_date(result);
}

Report make_day_report(const std::vector<Report>& reports)
{
	auto temperature_entries = get_entries_by_id(reports, "temperature");
	auto humidity_entries = get_entries_by_id(reports, "humidity");
	auto pressure_entries = get_entries_by_id(reports, "pressure");

	Report r {};
	r.datetime = reports.at(0).datetime;
	r.date = reports.at(0).date;
	r.temperature = get_average(temperature_entries);
	r.humidity = get_average(humidity_entries);
	r.pressure = get_average(pressure_entries);

	return r;
}
