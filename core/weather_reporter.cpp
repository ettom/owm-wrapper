#include "weather_reporter.h"
#include "core.h"
#include "reporter_helpers.h"


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

Report get_current_weather(const json& response)
{
	Report result;
	result.temperature = response["main"]["temp"].get<double>();
	result.humidity = response["main"]["humidity"].get<double>();
	result.pressure = response["main"]["pressure"].get<double>();
	result.date = unix_time_to_string(response["dt"].get<uint32_t>(), "%d.%m.%Y");
	return result;
}

std::vector<Report> get_reports(const json& response, int days)
{
	std::vector<Report> result;
	Forecasts_data forecasts = parse_forecast_data(response);

	int count = 0;
	for (auto [key,value] : forecasts) {
		if (count++ == days) {
			break;
		}
		result.push_back(make_day_report(forecasts, key));
	}

	return result;
}


Forecast get_forecast(const QueryParameters& q, WeatherGetter& getter)
{
	const WeatherData wd = get_weather_data(q, getter);
	Forecast f = get_main_data(wd);
	f.temperature_unit = q.temperature_unit;

	f.current_weather = get_current_weather(wd.current_weather_data);
	f.reports = get_reports(wd.forecast_data, q.days);

	return f;
}
