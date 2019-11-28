#include "weather_reporter.h"

WeatherData get_weather_data(QueryParameters q, const WeatherGetter& getter)
{
	WeatherData wd;

	q.url = OWM_TODAY_BASE_URL;
	wd.current_weather_data = json::parse(getter.get_weather_data(q));
	check_if_invalid_city(q.city, wd.current_weather_data);

	q.url = OWM_5_DAY_FORECAST_BASE_URL;
	wd.forecast_data = json::parse(getter.get_weather_data(q));
	check_if_invalid_city(q.city, wd.forecast_data);

	return wd;
}

Report get_current_weather(const QueryParameters& q, const json& response)
{
	Report r {};
	r.temperature = response["main"]["temp"].get<double>();
	r.humidity = response["main"]["humidity"].get<double>();
	r.pressure = response["main"]["pressure"].get<double>();
	r.datetime = response["dt"].get<time_t>() + q.timezone_offset;
	r.date = unix_time_to_string(r.datetime, r.date_format);
	return r;
}

std::vector<Report> get_reports(const QueryParameters& q, const json& response, const std::string& todays_date)
{
	reports_by_day reports = parse_forecast_data(response, q.timezone_offset);
	reports = remove_partial_days(reports);
	remove_todays_reports(reports, todays_date);
	return make_day_reports(q, reports);
}

Forecast get_forecast(const QueryParameters& q, const WeatherGetter& getter)
{
	const WeatherData wd = get_weather_data(q, getter);
	Forecast f = get_main_data(wd);

	f.temperature_unit = q.temperature_unit;
	f.current_weather = get_current_weather(q, wd.current_weather_data);
	f.reports = get_reports(q, wd.forecast_data, f.current_weather.date);

	return f;
}

json make_forecasts(QueryParameters q, const WeatherGetter& getter, const std::vector<std::string>& cities)
{
	json result = json::array();

	for (const auto& city : cities) {
		q.city = city;
		Forecast f = get_forecast(q, getter);
		result.push_back(f);
	}

	return result;
}
