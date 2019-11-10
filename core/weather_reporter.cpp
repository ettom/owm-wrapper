#include "weather_reporter.h"

WeatherData get_weather_data(QueryParameters q, const WeatherGetter& getter)
{
	WeatherData wd;

	q.url = "http://api.openweathermap.org/data/2.5/weather";
	wd.current_weather_data = json::parse(getter.get_weather_data(q));
	check_if_invalid_city(q.city, wd.current_weather_data);

	q.url = "http://api.openweathermap.org/data/2.5/forecast";
	wd.forecast_data = json::parse(getter.get_weather_data(q));
	check_if_invalid_city(q.city, wd.forecast_data);

	return wd;
}

Report get_current_weather(const json& response, const QueryParameters& q)
{
	Report r {};
	r.temperature = response["main"]["temp"].get<double>();
	r.humidity = response["main"]["humidity"].get<double>();
	r.pressure = response["main"]["pressure"].get<double>();
	r.datetime = response["dt"].get<time_t>() + q.timezone_offset;
	r.date = unix_time_to_string(r.datetime, r.date_format);
	return r;
}

std::vector<Report> get_reports(const json& response, const std::string& todays_date, const QueryParameters& q)
{
	std::vector<Report> day_reports;
	Reports_by_day reports = parse_forecast_data(response, q.timezone_offset);
	reports = remove_partial_days(reports);

	if (reports.at(0).at(0).date == todays_date) {
		reports.erase(reports.begin());
	}

	for (size_t i = 0; i < q.days; i++) {
		day_reports.push_back(make_day_report(reports.at(i)));
	}

	return day_reports;
}


Forecast get_forecast(const QueryParameters& q, const WeatherGetter& getter)
{
	const WeatherData wd = get_weather_data(q, getter);
	Forecast f = get_main_data(wd);

	f.temperature_unit = q.temperature_unit;
	f.current_weather = get_current_weather(wd.current_weather_data, q);
	f.reports = get_reports(wd.forecast_data, f.current_weather.date, q);

	return f;
}
