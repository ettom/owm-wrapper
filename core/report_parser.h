#pragma once
#include "core.h"
#include "exceptions.h"

#include <nlohmann/json.hpp>

#include <string>
#include <vector>

Forecast get_main_data(const WeatherData& wd);
std::string get_city(const nlohmann::json& response);

void check_if_invalid_city(const std::string& city, const nlohmann::json& response);

void remove_todays_reports(ReportsByDay& reports, const std::string& todays_date);

ReportsByDay remove_partial_days(const ReportsByDay& input);
ReportsByDay parse_forecast_data(const nlohmann::json& response, long timezone_offset);

Report make_single_day_report(const std::vector<Report>& reports);
std::vector<Report> make_day_reports(const QueryParameters& q, const ReportsByDay& reports);
