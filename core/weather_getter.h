#pragma once
#include "restclient-cpp/restclient.h"

#include "core.h"

class WeatherGetter
{
public:
	virtual ~WeatherGetter() {};
	virtual std::string get_weather_data(const QueryParameters& q) const
	{
		const RestClient::Response r {RestClient::get(create_url(q))};
		return r.body;
	}

private:
	std::string create_url(const QueryParameters& q) const
	{
		return q.url + "?q=" + q.city + "&lang=" + q.lang + "&APPID=" + q.api_key
		       + "&units=" + TemperatureUnit::for_OWM[q.temperature_unit];
	}
};
