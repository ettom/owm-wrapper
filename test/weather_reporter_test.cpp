#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "core.h"
#include "helpers.h"
#include "weather_reporter.h"
#include "weather_getter.h"
#include "comparison.h"
#include "exceptions.h"

#include "api_responses/_tallinn_current_weather_response.h"
#include "api_responses/_tallinn_forecast_response.h"
#include "api_responses/_sydney_forecast_response.h"
#include "api_responses/_sydney_current_weather_response.h"
#include "api_responses/_invalid_city_response.h"

#define GMT2_OFFSET        7200
#define GMT_MINUS12_OFFSET -43200


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
	.WillOnce(Return(tallinn_current_weather_response))
	.WillOnce(Return(tallinn_forecast_response));

	QueryParameters q { .city = "Tallinn", .timezone_offset = GMT2_OFFSET };

	// ACT
	Forecast result = get_forecast(q, getter);

	// ASSERT
	ASSERT_EQ(result.city, "Tallinn");
	ASSERT_EQ(result.coordinates, "59.44,24.75");
	ASSERT_EQ(result.temperature_unit, TemperatureUnit::CELSIUS);
}

TEST(WeatherReporter, givenCity_callingGetForecast_mustReturnForecastForNextThreeDays)
{
	// ARRANGE
	MockWeatherGetter getter;

	EXPECT_CALL(getter, get_weather_data(_))
	.Times(2)
	.WillOnce(Return(tallinn_current_weather_response))
	.WillOnce(Return(tallinn_forecast_response));

	QueryParameters q { .city = "Tallinn", .timezone_offset = GMT2_OFFSET };

	// ACT
	Forecast result = get_forecast(q, getter);

	// ASSERT
	ASSERT_EQ(result.reports.size(), std::size_t(3));
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
	.WillOnce(Return(tallinn_current_weather_response))
	.WillOnce(Return(tallinn_forecast_response));

	QueryParameters q { .city = "Tallinn", .timezone_offset = GMT2_OFFSET };

	Report expected_current_weather {
		.datetime = 1572269226,
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
	.WillOnce(Return(tallinn_current_weather_response))
	.WillOnce(Return(tallinn_forecast_response));

	QueryParameters q { .city = "Tallinn", .timezone_offset = GMT2_OFFSET };

	Report expected_next_day_report {
		.datetime = 1572314400,
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

TEST(WeatherReporter, givenCityInOtherTimeZone_callingGetForecast_mustReturnDateForCurrentWeather)
{
	// ARRANGE
	MockWeatherGetter getter;

	EXPECT_CALL(getter, get_weather_data(_))
	.Times(2)
	.WillOnce(Return(sydney_current_weather_response))
	.WillOnce(Return(sydney_forecast_response));

	QueryParameters q { .city = "Sydney", .timezone_offset = GMT_MINUS12_OFFSET };

	time_t expected_datetime = 1572666855; // "02.11.2019 03:54:15"
	std::string expected_date = "02.11.2019";

	// ACT
	Forecast result = get_forecast(q, getter);

	// ASSERT
	ASSERT_EQ(result.current_weather.datetime, expected_datetime);
	ASSERT_EQ(result.current_weather.date, expected_date);
}

TEST(WeatherReporter, givenCityInOtherTimeZone_callingGetForecast_mustReturnCorrectDateRangesForFirstForecastDay)
{
	// ARRANGE
	time_t timezone_offset = GMT_MINUS12_OFFSET;
	std::string expected_first_day_first_report_datetime = "03.11.2019 00:00:00";
	std::string expected_first_day_last_report_datetime = "03.11.2019 21:00:00";

	// ACT
	Reports_by_day reports = parse_forecast_data(json::parse(sydney_forecast_response), timezone_offset);

	reports = remove_partial_days(reports);
	Report first_day_first_report = reports.at(0).at(0);
	Report first_day_last_report = reports.at(0).at(7);

	std::string first_day_first_report_datetime = unix_time_to_string(first_day_first_report.datetime, "%d.%m.%Y %H:%M:%S");
	std::string first_day_last_report_datetime = unix_time_to_string(first_day_last_report.datetime, "%d.%m.%Y %H:%M:%S");

	// ASSERT
	ASSERT_EQ(expected_first_day_first_report_datetime, first_day_first_report_datetime);
	ASSERT_EQ(expected_first_day_last_report_datetime, first_day_last_report_datetime);
}

TEST(WeatherReporter, givenInvalidCity_callingGetForecast_mustThrowInvalidCityException)
{
	// ARRANGE
	MockWeatherGetter getter;

	EXPECT_CALL(getter, get_weather_data(_))
	.Times(1)
	.WillRepeatedly(Return(invalid_city_response));

	QueryParameters q { .city = "tln", .timezone_offset = GMT2_OFFSET };

	// ASSERT
	ASSERT_THROW(get_forecast(q, getter), InvalidCityException);
}
