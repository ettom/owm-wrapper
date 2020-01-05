#pragma once
#include "core.h"
#include "exceptions.h"
#include "reader_writer.h"
#include "weather_getter.h"

Forecast get_forecast(const QueryParameters& q, const WeatherGetter& getter);
nlohmann::json make_forecasts(QueryParameters q, const WeatherGetter& getter, const std::vector<std::string>& cities);
