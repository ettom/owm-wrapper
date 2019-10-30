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
	f.city = city;

	f.current_weather = get_current_weather(city, getter);
	f.forecasts = get_three_day_forecast(city, getter);

	return f;
}

Report get_current_weather(const std::string& city, WeatherGetter& getter)
{
	QueryParameters q {city};
	json response = to_json(getter.get_weather_data(q));
	check_if_invalid_city(city, response);

	Report result;
	return result;
}

std::vector<Report> get_three_day_forecast(const std::string& city, WeatherGetter& getter)
{
	QueryParameters q {city};
	json response = to_json(getter.get_weather_data(q));
	check_if_invalid_city(city, response);

	std::vector<Report> result;
	return result;
}
