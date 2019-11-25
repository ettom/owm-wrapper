#include "helpers.h"

std::string unix_time_to_string(time_t datetime, const char* format)
{
	const std::time_t tmp = datetime;
	const std::tm* t = std::gmtime(&tmp);
	std::stringstream ss;
	ss << std::put_time(t, format);
	return ss.str();
}

long get_system_timezone_offset()
{
	const auto when = std::time(nullptr);
	const auto tm = *std::localtime(&when);
	std::ostringstream os;
	os << std::put_time(&tm, "%z");
	const std::string s = os.str();
	// s is in ISO 8601 format: "±HHMM"
	const int h = std::stoi(s.substr(0, 3), nullptr, 10);
	const int m = std::stoi(s[0] + s.substr(3), nullptr, 10);

	return h * 3600 + m * 60;
}

std::vector<double> get_entries_by_id(const std::vector<Report>& input, const std::string& id)
{
	std::vector<double> result;
	std::transform(input.begin(), input.end(), std::back_inserter(result), [&](const auto& report) {
		json j = report;
		return j[id].get<double>();
	});
	return result;
}
