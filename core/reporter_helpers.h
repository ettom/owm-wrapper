#pragma once
#include <string>
#include <iomanip>
#include <cstdint>
#include <algorithm>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include "core.h"
#include "exceptions.h"

std::string unix_time_to_string(uint32_t datetime, const char* format);
void check_if_invalid_city(const std::string& city, const json& response);

Forecast get_main_data(const WeatherData& wd);

std::vector<Report> parse_forecast_data(const json& response);
Report make_day_report(const std::vector<Report>& reports);

Reports_by_day group_by_date(const std::vector<Report>& reports);
Reports_by_day remove_partial_days(const Reports_by_day& input);
