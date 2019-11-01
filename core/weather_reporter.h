#pragma once
#include "core.h"
#include "weather_getter.h"
#include "exceptions.h"
#include "helpers.h"
#include "report_parser.h"

Forecast get_forecast(const QueryParameters& q, WeatherGetter& getter);
