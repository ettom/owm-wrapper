#pragma once

#include "restclient-cpp/restclient.h"
#include <ctime>
#include <iostream>

#include "core.h"
#include "helpers.h"
#include "reader_writer.h"
#include "temperature_unit.h"

class WeatherGetter
{
public:
	WeatherGetter() {}

	WeatherGetter(bool logging_on)
	{
		this->logging_on = logging_on;
	}

	virtual ~WeatherGetter() {};

	virtual RestClient::Response get_api_response(const QueryParameters& q) const
	{
		const RestClient::Response r {RestClient::get(create_url(q))};

		if (logging_on) {
			log_response(q, r);
		}

		return r;
	}

	virtual std::string get_weather_data(const QueryParameters& q) const
	{
		return get_api_response(q).body;
	}

	static std::string create_url(const QueryParameters& q)
	{
		return q.url + "?q=" + q.city + "&lang=" + q.lang + "&APPID=" + q.api_key
		       + "&units=" + TemperatureUnit::for_OWM[q.temperature_unit];
	}

private:
	bool logging_on = false;
	static void log_response(const QueryParameters& q, const RestClient::Response& r)
	{
		json j {
		    {"datetime", unix_time_to_string(std::time(nullptr), "%d.%m.%Y %H:%M:%S")},
		    {"HTTP_response_code", r.code},
		    {"query_parameters",
		     {
			 {"url", create_url(q)},
			 {"city", q.city},
			 {"lang", q.lang},
			 {"api_key", q.api_key},
			 {"temperature_unit", TemperatureUnit::for_OWM[q.temperature_unit]},
		     }},
		    {"response_body", json::parse(r.body)},
		};

		ReaderWriter rw;
		rw.output_filename = LOG_FILENAME;
		rw.write_json_to_file(j, true);
	}
};
