#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include "core.h"
#include "restclient-cpp/restclient.h"
#include "weather_getter.h"

RestClient::Response get_response(const QueryParameters& q)
{
	const std::string url = WeatherGetter::create_url(q);
	return RestClient::get(url);
}

TEST(API, askingCurrentWeatherWithValidCity_mustReturnHTTP200)
{
	// ARRANGE
	const QueryParameters q {.city = "Tallinn", .url = OWM_TODAY_BASE_URL};

	// ACT
	const auto r = get_response(q);

	// ASSERT
	ASSERT_EQ(r.code, 200);
}

TEST(API, askingWeatherForecastWithValidCity_mustReturnHTTP200)
{
	// ARRANGE
	const QueryParameters q {.city = "Tallinn", .url = OWM_5_DAY_FORECAST_BASE_URL};

	// ACT
	const auto r = get_response(q);

	// ASSERT
	ASSERT_EQ(r.code, 200);
}

TEST(API, askingCurrentWeatherWithInvalidCity_mustReturnInvalidCityResponse)
{
	// ARRANGE
	const QueryParameters q {.city = "tln", .url = OWM_TODAY_BASE_URL};

	// ACT
	const auto r = get_response(q);
	const json response_body = json::parse(r.body);

	// ASSERT
	ASSERT_EQ(r.code, 404);
	ASSERT_EQ(response_body.at("message"), OWM_INVALID_CITY_RESPONSE);
}

TEST(API, askingWeatherForecastWithInvalidCity_mustReturnInvalidCityResponse)
{
	// ARRANGE
	const QueryParameters q {.city = "tln", .url = OWM_5_DAY_FORECAST_BASE_URL};

	// ACT
	const auto r = get_response(q);
	const json response_body = json::parse(r.body);

	// ASSERT
	ASSERT_EQ(r.code, 404);
	ASSERT_EQ(response_body.at("message"), OWM_INVALID_CITY_RESPONSE);
}

TEST(API, askingCurrentWeatherWithValidCity_mustReturnResponseContainingWeatherData)
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

TEST(API, askingWeatherForecastWithValidCity_mustReturnResponseContainingWeatherData)
{
	// ARRANGE
	const QueryParameters q {.city = "Tallinn", .url = OWM_5_DAY_FORECAST_BASE_URL};

	// ACT
	const auto r = get_response(q);
	const json response_body = json::parse(r.body);

	// ASSERT
	ASSERT_NO_THROW(response_body.at("list")[0].at("main").at("temp").get<double>());
	ASSERT_NO_THROW(response_body.at("list")[0].at("main").at("pressure").get<double>());
	ASSERT_NO_THROW(response_body.at("list")[0].at("main").at("humidity").get<double>());
}
