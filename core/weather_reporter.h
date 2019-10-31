#pragma once
#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include "core.h"
#include "weather_getter.h"
#include "parser.h"
#include "exceptions.h"

Forecast get_forecast(const QueryParameters& q, WeatherGetter& getter);
