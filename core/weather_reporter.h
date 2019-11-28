#pragma once
#include "core.h"
#include "exceptions.h"
#include "weather_getter.h"
#include "reader_writer.h"

Forecast get_forecast(const QueryParameters& q, const WeatherGetter& getter);
json make_forecasts(QueryParameters q, const WeatherGetter& getter, const std::vector<std::string>& cities);
