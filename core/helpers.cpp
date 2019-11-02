#include "helpers.h"

std::string unix_time_to_string(time_t datetime, const char* format)
{
	std::time_t tmp = datetime;
	std::tm* t = std::gmtime(&tmp);
	std::stringstream ss;
	ss << std::put_time(t, format);
	return ss.str();
}

long get_system_timezone_offset()
{
	auto when = std::time(nullptr);
	auto const tm = *std::localtime(&when);
	std::ostringstream os;
	os << std::put_time(&tm, "%z");
	std::string s = os.str();
	// s is in ISO 8601 format: "±HHMM"
	int h = std::stoi(s.substr(0, 3), nullptr, 10);
	int m = std::stoi(s[0] + s.substr(3), nullptr, 10);

	return h * 3600 + m * 60;
}

double round_to_two_decimal_points(double d)
{
	return std::ceil(d * 100) / 100;
}

struct average_accumulate_t {
	double sum;
	size_t n;
	double get_average() const
	{
		return round_to_two_decimal_points(sum / static_cast<double>(n));
	}
};

auto func_accumulate_average = [](average_accumulate_t acc_average, double value)
{
	return average_accumulate_t({
		acc_average.sum + value,
		acc_average.n + 1
	});
};

std::vector<double> get_entries_by_id(const std::vector<Report>& input, const std::string& id)
{
	std::vector<double> result;
	std::transform(input.begin(), input.end(), std::back_inserter(result),
	[&](auto & report) {
		json j = report;
		return j[id].get<double>();
	});
	return result;
}

double get_average(std::vector<double> input)
{
	average_accumulate_t res =
		std::accumulate(input.begin(),
				input.end(),
				average_accumulate_t({0, 0}),
				func_accumulate_average);

	return res.get_average();
}
