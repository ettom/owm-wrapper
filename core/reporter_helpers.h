#pragma once
#include <string>
#include <iomanip>
#include <cstdint>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include "core.h"
#include "exceptions.h"

std::string unix_time_to_string(uint32_t time_date_stamp, const std::string& format);

void check_if_invalid_city(const std::string& city, const json& response);
std::string get_city(const json& response);
std::string get_coordinates(const json& response);
Forecast get_main_data(const WeatherData& wd);

Forecasts_by_day parse_forecast_data(const json& response);
Report make_day_report(Forecasts_by_day forecasts, int day_number);
