#pragma once
#include "core.h"

#include <string>
#include <vector>

std::vector<double> get_entries_by_id(const std::vector<Report>& input, const std::string& id);
long get_system_timezone_offset();
time_t get_system_local_time();
std::string unix_time_to_string(time_t datetime, const char* format);

double round_to_decimal_points(double input, size_t decimal_points);
void round_numeric_fields(Report& r, size_t decimal_points);

template <class T>
double get_average(T input)
{
	double avg {};
	int count {1};
	for (const auto& e : input) {
		avg += (e - avg) / count;
		++count;
	}
	return avg;
}
