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

Report get_single_day_forecast(const json& response, int day_number);
std::map<std::string, std::vector<json>> parse_forecast_data(const json& response);
