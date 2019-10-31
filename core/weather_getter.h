#pragma once
#include <string>
#include <vector>
#include "core.h"


class WeatherGetter
{
public:
	virtual ~WeatherGetter() {};
	virtual std::string get_weather_data(const QueryParameters& q) const = 0;
private:
	std::string create_url(const QueryParameters q);
};
