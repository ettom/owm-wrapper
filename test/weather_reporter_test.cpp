#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "core.h"
#include "weather_reporter.h"
#include "weather_getter.h"
#include "comparison.h"
#include "exceptions.h"

#include "api_responses/_current_weather_response.h"
#include "api_responses/_forecast_weather_response.h"
#include "api_responses/_invalid_city_response.h"

class MockWeatherGetter : public WeatherGetter
{
public:
	MOCK_CONST_METHOD1(get_weather_data, std::string(const QueryParameters& q));
};


using namespace testing;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;


TEST(WeatherReporter, givenCity_callingGetForecast_mustReturnForecastData)
{
	// ARRANGE
	MockWeatherGetter getter;

	EXPECT_CALL(getter, get_weather_data(_))
	.Times(2)
	.WillOnce(Return(current_weather_response))
	.WillOnce(Return(forecast_weather_response));

	QueryParameters q { .city = "Tallinn" };

	// ACT
	Forecast result = get_forecast(q, getter);

	// ASSERT
	ASSERT_EQ(result.city, "Tallinn");
	ASSERT_EQ(result.coordinates, "59.44,24.75");
	ASSERT_EQ(result.temperature_unit, "Celsius");
}

TEST(WeatherReporter, givenCity_callingGetForecast_mustReturnForecastForNextThreeDays)
{
	// ARRANGE
	MockWeatherGetter getter;

	EXPECT_CALL(getter, get_weather_data(_))
	.Times(2)
	.WillOnce(Return(current_weather_response))
	.WillOnce(Return(forecast_weather_response));

	QueryParameters q { .city = "Tallinn" };
	// ACT
	Forecast result = get_forecast(q, getter);

	// ASSERT
	ASSERT_EQ(result.reports.size(), 3);
	ASSERT_EQ(result.reports.at(0).date, "29.10.2019");
	ASSERT_EQ(result.reports.at(1).date, "30.10.2019");
	ASSERT_EQ(result.reports.at(2).date, "31.10.2019");
}

TEST(WeatherReporter, givenCity_callingGetForecast_mustReturnCurrentWeatherReport)
{
	// ARRANGE
	MockWeatherGetter getter;

	EXPECT_CALL(getter, get_weather_data(_))
	.Times(2)
	.WillOnce(Return(current_weather_response))
	.WillOnce(Return(forecast_weather_response));

	QueryParameters q { .city = "Tallinn" };

	Report expected_current_weather {
		.datetime = 1572262026,
		.date = "28.10.2019",
		.temperature = 4.49,
		.humidity = 79,
		.pressure = 1009,
	};

	// ACT
	Forecast result = get_forecast(q, getter);

	// ASSERT
	ASSERT_EQ(result.current_weather, expected_current_weather);
}

TEST(WeatherReporter, givenCity_callingGetForecast_mustReturnForecastForNextDay)
{
	// ARRANGE
	MockWeatherGetter getter;

	EXPECT_CALL(getter, get_weather_data(_))
	.Times(2)
	.WillOnce(Return(current_weather_response))
	.WillOnce(Return(forecast_weather_response));

	QueryParameters q { .city = "Tallinn" };

	Report expected_next_day_report {
		.datetime = 1572307200,
		.date = "29.10.2019",
		.temperature = 1.94,
		.humidity = 68.88,
		.pressure = 1015.88,
	};

	// ACT
	Forecast result = get_forecast(q, getter);

	// ASSERT
	ASSERT_EQ(result.reports.at(0), expected_next_day_report);
}

TEST(WeatherReporter, givenInvalidCity_callingGetForecast_mustThrowInvalidCityException)
{
	// ARRANGE
	MockWeatherGetter getter;

	EXPECT_CALL(getter, get_weather_data(_))
	.Times(1)
	.WillRepeatedly(Return(invalid_city_response));

	QueryParameters q { .city = "tln" };

	// ASSERT
	ASSERT_THROW(get_forecast(q, getter), InvalidCityException);
}
