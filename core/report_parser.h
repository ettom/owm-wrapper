#pragma once
#include <algorithm>

#include "core.h"
#include "exceptions.h"
#include "helpers.h"

Forecast get_main_data(const WeatherData& wd);
std::string get_coordinates(const json& response);
std::string get_city(const json& response);

void check_if_invalid_city(const std::string& city, const json& response);

size_t find_report_by_date(const Reports_by_day& reports, const std::string& date);
Reports_by_day remove_partial_days(const Reports_by_day& input);
Reports_by_day group_by_date(const std::vector<Report>& reports);
Reports_by_day parse_forecast_data(const json& response, time_t timezone_offset);

Report make_day_report(const std::vector<Report>& reports);
