#pragma once
#include <string>
#include <vector>
#include <algorithm>

namespace TemperatureUnit
{
enum Unit { CELSIUS, FAHRENHEIT, KELVIN, SIZE_OF_ENUM };
static const std::string for_display[] { "Celsius", "Fahrenheit", "Kelvin" };
static const std::string for_OWM[] { "metric", "imperial", "default" };

static_assert(sizeof(for_display) / sizeof(std::string) == SIZE_OF_ENUM
	      , "Sizes don't match");
static_assert(sizeof(for_OWM) / sizeof(std::string) == SIZE_OF_ENUM
	      , "Sizes don't match");

inline Unit match_display_name_to_unit(const std::string& display_name)
{
	return static_cast<Unit>((std::distance(std::begin(for_display),
						std::find(std::begin(for_display),
								std::end(for_display),
								display_name))));
}
}
