#pragma once
#include <algorithm>
#include <array>
#include <string>
#include <vector>

namespace TemperatureUnit
{
enum Unit { celsius, fahrenheit, kelvin, size_of_enum };
static const char* for_display[] {"Celsius", "Fahrenheit", "Kelvin"};
static const char* for_OWM[] {"metric", "imperial", "default"};

static_assert(sizeof(for_display) / sizeof(char*) == size_of_enum, "Sizes don't match");
static_assert(sizeof(for_OWM) / sizeof(char*) == size_of_enum, "Sizes don't match");

inline Unit match_display_name_to_unit(const std::string& display_name)
{
	return static_cast<Unit>((std::distance(
		std::begin(for_display), std::find(std::begin(for_display), std::end(for_display), display_name))));
}

constexpr std::array<std::pair<const char*, Unit>, size_of_enum> make_unit_displayname_pairs()
{
	std::array<std::pair<const char*, Unit>, size_of_enum> result {};
	for (size_t i = 0; i < size_of_enum; ++i) {
		result[i] = {for_display[i], static_cast<Unit>(i)};
	}

	return result;
}
} // namespace TemperatureUnit
