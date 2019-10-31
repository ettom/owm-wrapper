#include "weather_reporter.h"

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
	Forecast f;
	f.coordinates = get_coordinates(wd.current_weather_data);
	f.city = get_city(wd.current_weather_data);
	return f;
}

WeatherData get_weather_data(const QueryParameters& q, WeatherGetter& getter)
{
	WeatherData wd;
	// q.url = current weather url;
	wd.current_weather_data = to_json(getter.get_weather_data(q));
	check_if_invalid_city(q.city, wd.current_weather_data);
	// create new q?
	// q.url = forecast url;
	wd.forecast_data = to_json(getter.get_weather_data(q));
	check_if_invalid_city(q.city, wd.forecast_data);

	return wd;
}

std::string unix_time_to_string(uint32_t time_date_stamp, const std::string& format)
{
	std::time_t tmp = time_date_stamp;
	std::tm* t = std::gmtime(&tmp);
	std::stringstream ss;
	ss << std::put_time(t, format.c_str());
	return ss.str();
}

Report get_current_weather(const json& response)
{
	Report result;
	result.temperature = response["main"]["temp"].get<double>();
	result.humidity = response["main"]["humidity"].get<double>();
	result.pressure = response["main"]["pressure"].get<double>();
	result.date = unix_time_to_string(response["dt"].get<uint32_t>(), "%d.%m.%Y");
	return result;
}

std::vector<Report> get_three_day_forecast(const json& response)
{
	std::vector<Report> result;
	return result;
}

Forecast get_forecast(const QueryParameters& q, WeatherGetter& getter)
{
	const WeatherData wd = get_weather_data(q, getter);
	Forecast f = get_main_data(wd);
	f.temperature_unit = q.temperature_unit;

	f.current_weather = get_current_weather(wd.current_weather_data);
	f.forecasts = get_three_day_forecast(wd.forecast_data);

	return f;
}

