#include "weather_reporter.h"

Forecast get_forecast(const std::string& city, WeatherGetter& getter)
{
	Forecast f;
	f.current_weather = get_current_weather(city, getter);
	f.forecasts = get_three_day_forecast(city, getter);
	return f;
}

Report get_current_weather(const std::string& city, WeatherGetter& getter)
{
	QueryParameters q;
	q.city = city;
	std::string response = getter.get_weather_data(q);

	Report result;
	return result;
}

std::vector<Report> get_three_day_forecast(const std::string& city, WeatherGetter& getter)
{
	QueryParameters q;
	q.city = city;
	std::string response = getter.get_weather_data(q);

	std::vector<Report> result;
	return result;
}
