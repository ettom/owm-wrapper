#pragma once
#include <string>
#include <iomanip>
#include <cstdint>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include "core.h"
#include "exceptions.h"

std::string get_city(const json& response);
void check_if_invalid_city(const std::string& city, const json& response);
std::string unix_time_to_string(uint32_t time_date_stamp, const std::string& format);
std::string get_coordinates(const json& response);
Forecast get_main_data(const WeatherData& wd);
