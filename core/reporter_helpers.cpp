#include "reporter_helpers.h"
#include "core.h"
#include <cstdint>
#include <iterator>

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

std::string unix_time_to_string(uint32_t datetime, const char* format)
{
	std::time_t tmp = datetime;
	std::tm* t = std::gmtime(&tmp);
	std::stringstream ss;
	ss << std::put_time(t, format);
	return ss.str();
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
	Forecast f;
	f.coordinates = get_coordinates(wd.current_weather_data);
	f.city = get_city(wd.current_weather_data);
	return f;
}

int find_report_by_date(const Forecasts_by_day& reports, const std::string& date)
{
	for (int i = 0; i < reports.size(); i++) {
		for (auto r : reports.at(i)) {
			if (r.date == date) {
				return i;
			}
		}
	}

	return -1;
}

Forecasts_by_day remove_partial_days(const Forecasts_by_day& input)
{
	Forecasts_by_day result;
	auto pred = [](auto & x) {
		return x.size() == 8;
	};

	std::copy_if(input.begin(), input.end(), std::back_inserter(result), pred);
	return result;
}

Forecasts_by_day group_by_date(const std::vector<Report>& reports)
{
	Forecasts_by_day result;
	for (auto r : reports) {
		int to_insert = find_report_by_date(result, r.date);
		if (to_insert == -1) {
			result.push_back(std::vector<Report> {r});
		} else {
			result.at(to_insert).push_back(r);
		}
	}

	return result;
}

std::vector<Report> parse_forecast_data(const json& response)
{
	std::vector<Report> result;

	for (auto& [key, value] : response["list"].items()) {
		Report r { .datetime = value["dt"].get<uint32_t>(),
			   .date = unix_time_to_string(r.datetime, r.date_format),
			   .temperature = value["main"]["temp"],
			   .humidity = value["main"]["humidity"],
			   .pressure = value["main"]["pressure"],
			 };
		result.push_back(r);
	}

	return result;
}

struct average_accumulate_t {
	double sum;
	size_t n;
	double get_average() const
	{
		return sum / n;
	}
};

auto func_accumulate_average =
	[](average_accumulate_t acc_average, double value)
{
	return average_accumulate_t({
		acc_average.sum + value,
		acc_average.n + 1
	});
};

std::vector<double> get_entries_by_id(const std::vector<Report>& input, const std::string& id)
{
	std::vector<double> result;
	std::transform(input.begin(), input.end(), std::back_inserter(result),
	[&](auto & report) {
		return report.at(id);
	});
	return result;
}

Report make_day_report(const std::vector<Report>& reports)
{
	Report result { .datetime = reports.at(0).datetime,
			.date = reports.at(0).date };

	auto temps = get_entries_by_id(reports, "temperature");
	average_accumulate_t res =
		std::accumulate(temps.begin(), temps.end(), average_accumulate_t({0, 0}), func_accumulate_average);
	result.temperature = res.get_average();
	return result;
}
