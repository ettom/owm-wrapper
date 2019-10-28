#include "weather_reporter.h"

Forecast get_forecast(std::string city, WeatherGetter& g)
{
	Forecast f;
	f.current_weather = get_current_weather(city, g);
	f.forecasts = get_three_day_forecast(city, g);
	return f;
}

Report get_current_weather(std::string city, WeatherGetter& g)
{
	QueryParameters q;
	q.city = city;
	std::string response = g.get_weather_data(q);

	Report result;
	return result;
}

std::vector<Report> get_three_day_forecast(std::string city, WeatherGetter& g)
{
	QueryParameters q;
	q.city = city;
	std::string response = g.get_weather_data(q);

	std::vector<Report> result;
	return result;
}
