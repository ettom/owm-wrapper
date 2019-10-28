#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "core.h"
#include "weather_reporter.h"
#include "weather_getter.h"
#include "comparison.h"

#include "_current_weather_response.h"
#include "_forecast_weather_response.h"

class MockWeatherGetter : public WeatherGetter
{
public:
	MOCK_METHOD1(get_weather_data, std::string(QueryParameters& q));
};


using namespace testing;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;


TEST(WeatherReporter, givenCity_callingGetForecast_mustReturnCurrentWeatherReport)
{
	// ARRANGE
	MockWeatherGetter getter;

	EXPECT_CALL(getter, get_weather_data(_))
	.Times(2)
	.WillOnce(Return(current_weather_response))
	.WillOnce(Return(forecast_weather_response));

	Report expected_current_weather;
	expected_current_weather.date = "28.10.2019";
	expected_current_weather.temperature = 4.78; // round to 2 decimal places
	expected_current_weather.pressure = 1009;
	expected_current_weather.humidity = 79;

	// ACT
	Forecast result = get_forecast("Tallinn", getter);

	// ASSERT
	ASSERT_EQ(result.city, "Tallinn");
	ASSERT_EQ(result.coordinate, "59.44,24.75");
	ASSERT_EQ(result.temperature_unit, "Celsius");

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

	Report expected_next_day_report;
	expected_next_day_report.date = "29.10.2019";
	expected_next_day_report.temperature = 1.94;
	expected_next_day_report.pressure = 1015.88;
	expected_next_day_report.humidity = 68.88;

	// ACT
	Forecast result = get_forecast("Tallinn", getter);

	// ASSERT
	ASSERT_EQ(result.city, "Tallinn");
	ASSERT_EQ(result.coordinate, "59.44,24.75");
	ASSERT_EQ(result.temperature_unit, "Celsius");

	ASSERT_EQ(result.forecasts.at(0), expected_next_day_report);
}
