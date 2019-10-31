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
	result.datetime = response["dt"].get<uint32_t>();
	result.date = unix_time_to_string(result.datetime, result.date_format);
	return result;
}

std::vector<Report> get_reports(const json& response, int days)
{
	std::vector<Report> result;
	Forecasts_by_day reports_by_day = group_by_date(parse_forecast_data(response));
	reports_by_day = remove_partial_days(reports_by_day);

	for (int i = 0; i <= days; i++) {
		result.push_back(make_day_report(reports_by_day.at(i)));

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
