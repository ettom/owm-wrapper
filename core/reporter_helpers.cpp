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

std::string unix_time_to_string(uint32_t time_date_stamp, const std::string& format)
{
	std::time_t tmp = time_date_stamp;
	std::tm* t = std::gmtime(&tmp);
	std::stringstream ss;
	ss << std::put_time(t, format.c_str());
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
