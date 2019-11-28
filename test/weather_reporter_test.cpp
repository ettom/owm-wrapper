#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "core.h"
#include "exceptions.h"
#include "helpers.h"
#include "reader_writer.h"
#include "report_parser.h"
#include "testing_helpers.h"
#include "weather_getter.h"
#include "weather_reporter.h"

#include "api_responses/invalid_city_response.h"
#include "api_responses/sydney_current_weather_response.h"
#include "api_responses/sydney_forecast_response.h"
#include "api_responses/tallinn_current_weather_response.h"
#include "api_responses/tallinn_forecast_response.h"

#define GMT2_OFFSET 7200
#define GMT_MINUS12_OFFSET -43200

class MockWeatherGetter : public WeatherGetter
{
public:
	MOCK_CONST_METHOD1(get_weather_data, std::string(const QueryParameters& q));
};

class MockReaderWriter : public ReaderWriter
{
public:
	MOCK_CONST_METHOD0(read_file, std::vector<std::string>());
	MOCK_CONST_METHOD1(write_json_to_file, void(const json& json));
};

using namespace testing;
using ::testing::_;
using ::testing::AtLeast;
using ::testing::Eq;
using ::testing::Return;

void read_cities_write_forecasts(const QueryParameters& q, const WeatherGetter& getter, const ReaderWriter& rw)
{
	const std::vector<std::string> cities = rw.read_file();
	const json result = make_forecasts(q, getter, cities);
	rw.write_json_to_file(result);
}

TEST(WeatherReporter, givenCityName_callingReadCitiesWriteForecasts_mustCallWriteToFileWithForecastJson)
{
	// ARRANGE
	MockReaderWriter rw;
	EXPECT_CALL(rw, read_file)
	    .Times(1) //
	    .WillOnce(Return(std::vector<std::string> {"Tallinn"}));

	const QueryParameters q {.timezone_offset = GMT2_OFFSET};

	const auto expected_json = R"(
[
{
    "city": "Tallinn",
    "coordinates": "59.44,24.75",
    "current_weather": {
        "date": "28.10.2019",
        "datetime": 1572269226,
        "humidity": 79.0,
        "pressure": 1009.0,
        "temperature": 4.49
    },
    "reports": [
        {
            "date": "29.10.2019",
            "datetime": 1572314400,
            "humidity": 68.88,
            "pressure": 1015.88,
            "temperature": 1.94
        },
        {
            "date": "30.10.2019",
            "datetime": 1572400800,
            "humidity": 70.38,
            "pressure": 1023.0,
            "temperature": 1.77
        },
        {
            "date": "31.10.2019",
            "datetime": 1572487200,
            "humidity": 79.0,
            "pressure": 1014.63,
            "temperature": 4.8
        }
    ],
    "temperature_unit": "Celsius"
}
]
)"_json;

	const MockWeatherGetter getter;
	EXPECT_CALL(getter, get_weather_data(_))
	    .Times(2)
	    .WillOnce(Return(tallinn_current_weather_response))
	    .WillOnce(Return(tallinn_forecast_response));

	// ASSERT
	EXPECT_CALL(rw, write_json_to_file(Eq(expected_json))).Times(1);
	read_cities_write_forecasts(q, getter, rw);
}

TEST(WeatherReporter, givenInvalidCityName_callingReadCitiesWriteForecasts_mustNotCallWriteToFile)
{
	// ARRANGE
	MockReaderWriter rw;
	EXPECT_CALL(rw, read_file)
	    .Times(1) //
	    .WillOnce(Return(std::vector<std::string> {"tln"}));

	const QueryParameters q {.timezone_offset = GMT2_OFFSET};

	const MockWeatherGetter getter;
	EXPECT_CALL(getter, get_weather_data(_))
	    .Times(1) //
	    .WillOnce(Return(invalid_city_response));

	// ASSERT
	EXPECT_CALL(rw, write_json_to_file(_)).Times(0);
	ASSERT_THROW(read_cities_write_forecasts(q, getter, rw), InvalidCityException);
}

TEST(WeatherReporter, givenCity_callingGetForecast_mustReturnForecastData)
{
	// ARRANGE
	const MockWeatherGetter getter;

	EXPECT_CALL(getter, get_weather_data(_))
	    .Times(2)
	    .WillOnce(Return(tallinn_current_weather_response))
	    .WillOnce(Return(tallinn_forecast_response));

	const QueryParameters q {.city = "Tallinn", .timezone_offset = GMT2_OFFSET};

	// ACT
	const Forecast result = get_forecast(q, getter);

	// ASSERT
	ASSERT_EQ(result.city, "Tallinn");
	ASSERT_EQ(result.coordinates, "59.44,24.75");
	ASSERT_EQ(result.temperature_unit, TemperatureUnit::CELSIUS);
}

TEST(WeatherReporter, givenCity_callingGetForecast_mustReturnForecastForNextThreeDays)
{
	// ARRANGE
	const MockWeatherGetter getter;

	EXPECT_CALL(getter, get_weather_data(_))
	    .Times(2)
	    .WillOnce(Return(tallinn_current_weather_response))
	    .WillOnce(Return(tallinn_forecast_response));

	const QueryParameters q {.city = "Tallinn", .timezone_offset = GMT2_OFFSET};

	// ACT
	const Forecast result = get_forecast(q, getter);

	// ASSERT
	ASSERT_EQ(result.reports.size(), std::size_t(3));
	ASSERT_EQ(result.reports.at(0).date, "29.10.2019");
	ASSERT_EQ(result.reports.at(1).date, "30.10.2019");
	ASSERT_EQ(result.reports.at(2).date, "31.10.2019");
}

TEST(WeatherReporter, givenCity_callingGetForecast_mustReturnCurrentWeatherReport)
{
	// ARRANGE
	const MockWeatherGetter getter;

	EXPECT_CALL(getter, get_weather_data(_))
	    .Times(2)
	    .WillOnce(Return(tallinn_current_weather_response))
	    .WillOnce(Return(tallinn_forecast_response));

	const QueryParameters q {.city = "Tallinn", .timezone_offset = GMT2_OFFSET};

	const Report expected_current_weather {
	    .datetime = 1572269226,
	    .date = "28.10.2019",
	    .temperature = 4.49,
	    .humidity = 79,
	    .pressure = 1009,
	};

	// ACT
	const Forecast result = get_forecast(q, getter);

	// ASSERT
	ASSERT_EQ(result.current_weather, expected_current_weather);
}

TEST(WeatherReporter, givenCity_callingGetForecast_mustReturnForecastForNextDay)
{
	// ARRANGE
	const MockWeatherGetter getter;

	EXPECT_CALL(getter, get_weather_data(_))
	    .Times(2)
	    .WillOnce(Return(tallinn_current_weather_response))
	    .WillOnce(Return(tallinn_forecast_response));

	const QueryParameters q {.city = "Tallinn", .timezone_offset = GMT2_OFFSET};

	const Report expected_next_day_report {
	    .datetime = 1572314400,
	    .date = "29.10.2019",
	    .temperature = 1.94,
	    .humidity = 68.88,
	    .pressure = 1015.88,
	};

	// ACT
	const Forecast result = get_forecast(q, getter);

	// ASSERT
	ASSERT_EQ(result.reports.at(0), expected_next_day_report);
}

TEST(WeatherReporter, givenCityInOtherTimeZone_callingGetForecast_mustReturnDateForCurrentWeather)
{
	// ARRANGE
	const MockWeatherGetter getter;

	EXPECT_CALL(getter, get_weather_data(_))
	    .Times(2)
	    .WillOnce(Return(sydney_current_weather_response))
	    .WillOnce(Return(sydney_forecast_response));

	const QueryParameters q {.city = "Sydney", .timezone_offset = GMT_MINUS12_OFFSET};

	const time_t expected_datetime = 1572666855; // "02.11.2019 03:54:15"
	const std::string expected_date = "02.11.2019";

	// ACT
	const Forecast result = get_forecast(q, getter);

	// ASSERT
	ASSERT_EQ(result.current_weather.datetime, expected_datetime);
	ASSERT_EQ(result.current_weather.date, expected_date);
}

TEST(WeatherReporter, givenCityInOtherTimeZone_callingParseForecastData_mustReturnCorrectDateRangesForFirstForecastDay)
{
	// ARRANGE
	const time_t timezone_offset = GMT_MINUS12_OFFSET;
	const std::string expected_first_day_first_report_datetime = "03.11.2019 00:00:00";
	const std::string expected_first_day_last_report_datetime = "03.11.2019 21:00:00";

	// ACT
	const reports_by_day reports = parse_forecast_data(json::parse(sydney_forecast_response), timezone_offset);

	const Report first_day_first_report = reports.at(0).at(0);
	const Report first_day_last_report = reports.at(0).at(7);

	const std::string first_day_first_report_datetime =
	    unix_time_to_string(first_day_first_report.datetime, "%d.%m.%Y %H:%M:%S");
	const std::string first_day_last_report_datetime =
	    unix_time_to_string(first_day_last_report.datetime, "%d.%m.%Y %H:%M:%S");

	// ASSERT
	ASSERT_EQ(expected_first_day_first_report_datetime, first_day_first_report_datetime);
	ASSERT_EQ(expected_first_day_last_report_datetime, first_day_last_report_datetime);
}

TEST(WeatherReporter, givenInvalidCity_callingGetForecast_mustThrowInvalidCityException)
{
	// ARRANGE
	const MockWeatherGetter getter;

	EXPECT_CALL(getter, get_weather_data(_))
	    .Times(1) //
	    .WillRepeatedly(Return(invalid_city_response));

	const QueryParameters q {.city = "tln", .timezone_offset = GMT2_OFFSET};

	// ASSERT
	ASSERT_THROW(get_forecast(q, getter), InvalidCityException);
}

TEST(WeatherReporter, givenForecastAsJson_convertingToForecastAndBack_mustReturnForecastAsJson)
{
	// ARRANGE
	const auto input = R"(
{
    "city": "Tallinn",
    "coordinates": "59.44,24.75",
    "current_weather": {
        "date": "04.11.2019",
        "datetime": 1572826536,
        "humidity": 80.0,
        "pressure": 998.0,
        "temperature": 4.71
    },
    "reports": [
        {
            "date": "05.11.2019",
            "datetime": 1572919200,
            "humidity": 79.5,
            "pressure": 995.88,
            "temperature": 3.33
        },
        {
            "date": "06.11.2019",
            "datetime": 1573005600,
            "humidity": 77.38,
            "pressure": 998.5,
            "temperature": 2.27
        },
        {
            "date": "07.11.2019",
            "datetime": 1573092000,
            "humidity": 85.0,
            "pressure": 1007.13,
            "temperature": 0.45
        }
    ],
    "temperature_unit": "Fahrenheit"
}
)"_json;

	// ACT
	Forecast result_forecast;
	json result_json;
	from_json(input, result_forecast);
	to_json(result_json, result_forecast);

	// ASSERT
	ASSERT_EQ(result_json, input);
}
