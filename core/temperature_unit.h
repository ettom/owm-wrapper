#pragma once
#include <algorithm>
#include <array>
#include <string>
#include <vector>

namespace TemperatureUnit
{
enum Unit { CELSIUS, FAHRENHEIT, KELVIN, SIZE_OF_ENUM };
static const char* for_display[] { "Celsius", "Fahrenheit", "Kelvin" };
static const char* for_OWM[] { "metric", "imperial", "default" };

static_assert(sizeof(for_display) / sizeof(char*) == SIZE_OF_ENUM, "Sizes don't match");
static_assert(sizeof(for_OWM) / sizeof(char*) == SIZE_OF_ENUM, "Sizes don't match");

inline Unit match_display_name_to_unit(const std::string& display_name)
{
	return static_cast<Unit>((std::distance(
	    std::begin(for_display), std::find(std::begin(for_display), std::end(for_display), display_name))));
}

constexpr std::array<std::pair<Unit, const char*>, SIZE_OF_ENUM> make_unit_displayname_pairs()
{
	std::array<std::pair<Unit, const char*>, SIZE_OF_ENUM> result;
	for (size_t i = 0; i < SIZE_OF_ENUM; ++i) {
		result[i] = std::make_pair(static_cast<Unit>(i), for_display[i]);
	}

	return result;
}
} // namespace TemperatureUnit
