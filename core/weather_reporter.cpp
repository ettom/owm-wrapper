#include "weather_reporter.h"

void check_if_invalid_city(const std::string& city, json& response)
{
	if (get_string_value(response["name"]) != city
			&& get_string_value(response["city"]["name"]) != city) {
		throw InvalidCityException();
	}
}

Forecast get_forecast(const std::string& city, WeatherGetter& getter)
{
	Forecast f;

WeatherData get_weather_data(const std::string& city, WeatherGetter& getter)
{
	QueryParameters q {city};
	WeatherData wd;

	// q.url = current weather url;
	wd.current_weather_data = to_json(getter.get_weather_data(q));
	// q.url = forecast url;
	wd.forecast_data = to_json(getter.get_weather_data(q));

	check_if_invalid_city(city, wd.current_weather_data);
	check_if_invalid_city(city, wd.forecast_data);
	return wd;
}

Forecast get_forecast(const std::string& city, WeatherGetter& getter)
{
	const WeatherData wd = get_weather_data(city, getter);

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
