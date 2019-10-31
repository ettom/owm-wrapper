#include "weather_reporter.h"

std::string get_city(json response)
{
	return get_string_value((response["name"].is_null()) ? response["city"]["name"] : response["name"]);
}

void check_if_invalid_city(const std::string& city, json& response)
{
	if (get_city(response) != city) {
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
	f.city = get_city(wd.current_weather_data);
	return f;
}

WeatherData get_weather_data(QueryParameters& q, WeatherGetter& getter)
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


Forecast get_forecast(QueryParameters& q, WeatherGetter& getter)
{
	const WeatherData wd = get_weather_data(q, getter);
	Forecast f = get_main_data(wd);

	f.current_weather = get_current_weather(wd);
	f.forecasts = get_three_day_forecast(wd);

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
