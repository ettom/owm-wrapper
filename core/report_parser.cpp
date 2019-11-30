#include <algorithm>

#include "helpers.h"
#include "report_parser.h"

std::string get_city(const json& response)
{
	if (response.count("name")) {
		return response["name"].get<std::string>();
	} else if (response.count("city")) {
		return response["city"]["name"].get<std::string>();
	} else {
		throw InvalidCityException("Could not extract city from API response!");
	}
}

void check_if_invalid_city(const std::string& city, const json& response)
{
	if (response.count("message") && response["message"] == OWM_INVALID_CITY_RESPONSE) {
		throw InvalidCityException("Given city " + city + " is invalid.");
	}
}

std::string get_coordinates(const json& response)
{
	const json coordinates {(response["coord"].is_null()) ? response["city"]["coord"] : response["coord"]};
	return coordinates["lat"].dump() + "," + coordinates["lon"].dump();
}

Forecast get_main_data(const WeatherData& wd)
{
	Forecast f {};
	f.coordinates = get_coordinates(wd.current_weather_data);
	f.city = get_city(wd.current_weather_data);
	return f;
}

ReportsByDay remove_partial_days(const ReportsByDay& input)
{
	ReportsByDay result;
	const auto pred = [](auto& x) { return x.size() == REPORTS_PER_DAY_IN_FORECAST; };

	std::copy_if(input.begin(), input.end(), std::back_inserter(result), pred);
	return result;
}

void remove_todays_reports(ReportsByDay& reports, const std::string& todays_date)
{
	if (reports.at(0).at(0).date == todays_date) {
		reports.erase(reports.begin());
	}
}

size_t find_report_by_date(const ReportsByDay& reports, const std::string& date)
{
	for (size_t i = 0; i < reports.size(); i++) {
		for (const auto& r : reports.at(i)) {
			if (r.date == date) {
				return i;
			}
		}
	}

	return std::string::npos;
}

ReportsByDay group_by_date(const std::vector<Report>& reports)
{
	ReportsByDay result;
	for (const auto& r : reports) {
		const size_t to_insert {find_report_by_date(result, r.date)};
		if (to_insert == std::string::npos) {
			result.push_back(std::vector<Report> {r});
		} else {
			result.at(to_insert).push_back(r);
		}
	}

	return result;
}

ReportsByDay parse_forecast_data(const json& response, time_t timezone_offset)
{
	std::vector<Report> result;

	for (const auto& [key, value] : response["list"].items()) {
		Report r {};
		r.datetime = value["dt"].get<time_t>() + timezone_offset;
		r.date = unix_time_to_string(r.datetime, r.date_format);
		r.temperature = value["main"]["temp"];
		r.humidity = value["main"]["humidity"];
		r.pressure = value["main"]["pressure"];
		result.push_back(r);
	}

	return remove_partial_days(group_by_date(result));
}

Report make_single_day_report(const std::vector<Report>& reports)
{
	Report r {};
	r.datetime = reports.at(0).datetime;
	r.date = reports.at(0).date;
	r.temperature = get_average(get_entries_by_id(reports, "temperature"));
	r.humidity = get_average(get_entries_by_id(reports, "humidity"));
	r.pressure = get_average(get_entries_by_id(reports, "pressure"));

	return r;
}

std::vector<Report> make_day_reports(const QueryParameters& q, const ReportsByDay& reports)
{
	std::vector<Report> day_reports;
	for (size_t i = 0; i < q.days; i++) {
		Report tmp = make_single_day_report(reports.at(i));
		round_numeric_fields(tmp, q.decimal_points);
		day_reports.push_back(tmp);
	}
	return day_reports;
}
