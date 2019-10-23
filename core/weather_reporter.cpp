#include "weather_reporter.h"

Forecast get_forecast(std::string city, WeatherGetter& g)
{
	QueryParameters q;
	q.city = city;
	std::string response = g.get_weather_data(q);

	Forecast f;
	return f;
}

Report get_current_weather(std::string city, WeatherGetter& g)
{
	Report result;
	return result;
}

std::vector<Report> get_three_day_forecast(std::string city, WeatherGetter& g)
{
	std::vector<Report> result;

	return result;
}
