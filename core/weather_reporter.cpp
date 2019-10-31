#include "weather_reporter.h"

WeatherData get_weather_data(const QueryParameters& q, WeatherGetter& getter)
{
	WeatherData wd;
	// q.url = current weather url;
	wd.current_weather_data = json::parse(getter.get_weather_data(q));
	check_if_invalid_city(q.city, wd.current_weather_data);
	// create new q?
	// q.url = forecast url;
	wd.forecast_data = json::parse(getter.get_weather_data(q));
	check_if_invalid_city(q.city, wd.forecast_data);

	return wd;
}

Report get_current_weather(const json& response)
{
	Report r {};
	r.temperature = response["main"]["temp"].get<double>();
	r.humidity = response["main"]["humidity"].get<double>();
	r.pressure = response["main"]["pressure"].get<double>();
	r.datetime = response["dt"].get<uint32_t>();
	r.date = unix_time_to_string(r.datetime, r.date_format);
	return r;
}

std::vector<Report> get_reports(const json& response, size_t days)
{
	std::vector<Report> day_reports;
	Reports_by_day reports = group_by_date(parse_forecast_data(response));
	reports = remove_partial_days(reports);

	for (size_t i = 0; i <= days; i++) {
		day_reports.push_back(make_day_report(reports.at(i)));
	}

	return day_reports;
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
