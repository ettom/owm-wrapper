#include "reporter_helpers.h"

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

void remove_partial_days(Forecasts_data& input)
{
	for (auto it = input.cbegin(); it != input.cend();) {
		if (it->second.size() != 8) { // every day must have 8 entries
			input.erase(it++);
		} else {
			++it;
		}
	}
}

Forecasts_data parse_forecast_data(const json& response)
{
	Forecasts_data result;

	for (auto& el : response["list"].items()) {
		uint32_t datetime = el.value()["dt"];
		if (! result.count(datetime)) {
			result.insert(std::pair<uint32_t, std::vector<json>>(datetime, std::vector<json>()));
		}

		result.at(datetime).push_back(el.value()["main"]);
	}

	remove_partial_days(result);
	return result;
}


Report make_day_report(Forecasts_data forecasts, uint32_t datetime)
{
	Report result { .datetime = datetime, .date = unix_time_to_string(datetime, result.date_format) };
	return result;
}
