#pragma once
#include <string>
#include <vector>
#include "core.h"


class WeatherGetter
{
public:
	virtual ~WeatherGetter() {};
	virtual std::string get_weather_data(QueryParameters& q) = 0;
private:
	std::string create_url(QueryParameters q);
};
