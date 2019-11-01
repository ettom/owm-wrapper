#include "helpers.h"

std::string unix_time_to_string(uint32_t datetime, const char* format)
{
	std::time_t tmp = datetime;
	std::tm* t = std::gmtime(&tmp);
	std::stringstream ss;
	ss << std::put_time(t, format);
	return ss.str();
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
