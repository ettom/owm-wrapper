#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include "core.h"
#include "restclient-cpp/restclient.h"
#include "weather_getter.h"

const bool LOGGING_ON = true;

RestClient::Response get_response(const QueryParameters& q)
{
	WeatherGetter getter {LOGGING_ON};
	return getter.get_api_response(q);
}

TEST(API, askingCurrentWeatherForValidCity_mustReturnHTTP200)
{
	// ARRANGE
	const QueryParameters q {.city = "Tallinn", .url = OWM_TODAY_BASE_URL};

	// ACT
	const auto r = get_response(q);

	// ASSERT
	ASSERT_EQ(r.code, 200);
}

TEST(API, askingWeatherForecastForValidCity_mustReturnHTTP200)
{
	// ARRANGE
	const QueryParameters q {.city = "Tallinn", .url = OWM_5_DAY_FORECAST_BASE_URL};

	// ACT
	const auto r = get_response(q);

	// ASSERT
	ASSERT_EQ(r.code, 200);
}

TEST(API, askingCurrentWeatherForInvalidCity_mustReturnInvalidCityResponse)
{
	// ARRANGE
	const QueryParameters q {.city = "invalidcity", .url = OWM_TODAY_BASE_URL};

	// ACT
	const auto r = get_response(q);
	const json response_body = json::parse(r.body);

	// ASSERT
	ASSERT_EQ(r.code, 404);
	ASSERT_EQ(response_body.at("message"), OWM_INVALID_CITY_RESPONSE);
}

TEST(API, askingWeatherForecastForInvalidCity_mustReturnInvalidCityResponse)
{
	// ARRANGE
	const QueryParameters q {.city = "invalidcity", .url = OWM_5_DAY_FORECAST_BASE_URL};

	// ACT
	const auto r = get_response(q);
	const json response_body = json::parse(r.body);

	// ASSERT
	ASSERT_EQ(r.code, 404);
	ASSERT_EQ(response_body.at("message"), OWM_INVALID_CITY_RESPONSE);
}

TEST(API, askingCurrentWeatherForValidCity_mustReturnResponseContainingWeatherData)
{
	// ARRANGE
	const QueryParameters q {.city = "Tallinn", .url = OWM_TODAY_BASE_URL};

	// ACT
	const auto r = get_response(q);
	const json response_body = json::parse(r.body);

	// ASSERT
	ASSERT_NO_THROW(response_body.at("main").at("temp").get<double>());
	ASSERT_NO_THROW(response_body.at("main").at("humidity").get<double>());
	ASSERT_NO_THROW(response_body.at("main").at("pressure").get<double>());
}

TEST(API, askingWeatherForecastForValidCity_mustReturnResponseContainingWeatherData)
{
	// ARRANGE
	const QueryParameters q {.city = "Tallinn", .url = OWM_5_DAY_FORECAST_BASE_URL};

	// ACT
	const auto r = get_response(q);
	const json response_body = json::parse(r.body);

	// ASSERT
	ASSERT_NO_THROW(response_body.at("list").at(0).at("main").at("temp").get<double>());
	ASSERT_NO_THROW(response_body.at("list").at(0).at("main").at("pressure").get<double>());
	ASSERT_NO_THROW(response_body.at("list").at(0).at("main").at("humidity").get<double>());
}
