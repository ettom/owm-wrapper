#pragma once
#include "core.h"

inline void PrintTo(const Report& report, std::ostream* os)
{
	nlohmann::json j = report;
	*os << j.dump(4);
}

inline void PrintTo(const WeatherData& wd, std::ostream* os)
{
	*os << "  current_weather_data = " << wd.current_weather_data.dump(4) << std::endl
	    << "\t\tforecast_data = " << wd.forecast_data.dump(4) << std::endl;
}

namespace nlohmann
{
inline void PrintTo(json const& j, std::ostream* os)
{
	*os << j.dump(4);
}
} // namespace nlohmann
