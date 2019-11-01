#include <iostream>
#include <string>

#include "core.h"
#include "weather_getter.h"
#include "weather_reporter.h"

int main()
{
	QueryParameters q {};
	q.city = "Tallinn";

	WeatherGetter getter;
	Forecast f = get_forecast(q, getter);

	json j = f;
	std::cout << j.dump(4) << std::endl;

	return EXIT_SUCCESS;
}
