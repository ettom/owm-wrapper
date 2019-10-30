#pragma once
#include "core.h"
#include "weather_getter.h"

Forecast get_forecast(const std::string& city, WeatherGetter& getter);

Report get_current_weather(const std::string& city, WeatherGetter& getter);
std::vector<Report> get_three_day_forecast(const std::string& city, WeatherGetter& getter);
