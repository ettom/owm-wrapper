#pragma once
#include "core.h"
#include "weather_getter.h"

Forecast get_forecast(std::string city, WeatherGetter& g);

Report get_current_weather(std::string city, WeatherGetter& g);
std::vector<Report> get_three_day_forecast(std::string city, WeatherGetter& g);
