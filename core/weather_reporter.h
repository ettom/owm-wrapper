#pragma once
#include "core.h"
#include "exceptions.h"
#include "helpers.h"
#include "report_parser.h"
#include "weather_getter.h"

Forecast get_forecast(const QueryParameters& q, const WeatherGetter& getter);
