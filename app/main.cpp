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

	return 0;
}
