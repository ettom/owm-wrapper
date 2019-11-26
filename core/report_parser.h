#pragma once
#include <algorithm>

#include "core.h"
#include "exceptions.h"
#include "helpers.h"

Forecast get_main_data(const WeatherData& wd);
std::string get_coordinates(const json& response);
std::string get_city(const json& response);

void check_if_invalid_city(const std::string& city, const json& response);

size_t find_report_by_date(const reports_by_day& reports, const std::string& date);

void remove_todays_reports(reports_by_day& reports, const std::string& todays_date);

reports_by_day remove_partial_days(const reports_by_day& input);
reports_by_day group_by_date(const std::vector<Report>& reports);
reports_by_day parse_forecast_data(const json& response, time_t timezone_offset);

Report make_single_day_report(const std::vector<Report>& reports);
