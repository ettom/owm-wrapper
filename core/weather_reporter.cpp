#include "weather_reporter.h"

void check_if_invalid_city(const std::string& city, json& response)
{
	if (get_string_value(response["name"]) != city
			&& get_string_value(response["city"]["name"]) != city) {
		throw InvalidCityException();
	}
}

std::string get_coordinates(json response)
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
	return f;
}

WeatherData get_weather_data(const std::string& city, WeatherGetter& getter)
{
	QueryParameters q {city};
	WeatherData wd;

	// q.url = current weather url;
	wd.current_weather_data = to_json(getter.get_weather_data(q));
	check_if_invalid_city(city, wd.current_weather_data);
	// q.url = forecast url;
	wd.forecast_data = to_json(getter.get_weather_data(q));
	check_if_invalid_city(city, wd.forecast_data);

	return wd;
}


Forecast get_forecast(const std::string& city, WeatherGetter& getter)
{
	const WeatherData wd = get_weather_data(city, getter);
	Forecast f = get_main_data(wd);

	f.current_weather = get_current_weather(wd);
	f.forecasts = get_three_day_forecast(wd);

	f.city = city;

	return f;
}

Report get_current_weather(const WeatherData& wd)
{
	Report result;
	return result;
}

std::vector<Report> get_three_day_forecast(const WeatherData& wd)
{
	std::vector<Report> result;
	return result;
}
