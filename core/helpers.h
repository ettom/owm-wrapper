#pragma once
#include <iomanip>
#include <cstdint>
#include <algorithm>

#include "core.h"
#include "exceptions.h"

std::string unix_time_to_string(uint32_t datetime, const char* format);
std::vector<double> get_entries_by_id(const std::vector<Report>& input, const std::string& id);
double get_average(std::vector<double> input);
