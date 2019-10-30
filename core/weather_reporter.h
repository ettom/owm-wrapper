#pragma once
#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include "core.h"
#include "weather_getter.h"
#include "parser.h"
#include "exceptions.h"

Forecast get_forecast(const std::string& city, WeatherGetter& getter);

Report get_current_weather(const WeatherData& wd);
std::vector<Report> get_three_day_forecast(const WeatherData& wd);
