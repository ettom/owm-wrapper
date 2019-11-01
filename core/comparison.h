#pragma once
#include "core.h"

bool operator==(const Report& report1, const Report& report2)
{
	return report1.date == report2.date &&
	       report1.datetime == report2.datetime &&
	       std::string(report1.date_format) == std::string(report2.date_format) &&
	       report1.temperature == report2.temperature &&
	       report1.humidity == report2.humidity &&
	       report1.pressure == report2.pressure;
}

bool operator==(const Forecast& forecast1, const Forecast& forecast2)
{
	return forecast1.city == forecast2.city &&
	       forecast1.coordinates == forecast2.coordinates &&
	       forecast1.temperature_unit == forecast2.temperature_unit &&
	       forecast1.current_weather == forecast2.current_weather &&
	       forecast1.reports == forecast2.reports;
}
