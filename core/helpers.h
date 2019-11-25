#pragma once
#include <algorithm>
#include <iomanip>
#include <sstream>

#include "core.h"
#include "exceptions.h"

std::vector<double> get_entries_by_id(const std::vector<Report>& input, const std::string& id);
long get_system_timezone_offset();
std::string unix_time_to_string(time_t datetime, const char* format);

inline double round_to_decimal_points(double input, size_t decimal_points)
{
	const double multiplier = std::pow(10.0, decimal_points);
	return std::ceil(input * multiplier) / multiplier;
}

inline void round_numeric_fields(Report& r, size_t decimal_points)
{
	r.humidity = round_to_decimal_points(r.humidity, decimal_points);
	r.temperature = round_to_decimal_points(r.temperature, decimal_points);
	r.pressure = round_to_decimal_points(r.pressure, decimal_points);
}

template <class T>
inline double get_average(T input)
{
	double avg {};
	int count = 1;
	for (const auto& e : input) {
		avg += (e - avg) / count;
		++count;
	}
	return avg;
}
