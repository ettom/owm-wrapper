#pragma once
#include <string>

std::string current_weather_response = R"(
{
  "coord": {
    "lon": 24.75,
    "lat": 59.44
  },
  "weather": [
    {
      "id": 802,
      "main": "Clouds",
      "description": "scattered clouds",
      "icon": "03d"
    }
  ],
  "base": "stations",
  "main": {
    "temp": 4.49,
    "pressure": 1009,
    "humidity": 79,
    "temp_min": 4,
    "temp_max": 5.56
  },
  "visibility": 10000,
  "wind": {
    "speed": 2.6,
    "deg": 220
  },
  "rain": {},
  "clouds": {
    "all": 40
  },
  "dt": 1572262026,
  "sys": {
    "type": 1,
    "id": 1330,
    "country": "EE",
    "sunrise": 1572240571,
    "sunset": 1572273594
  },
  "timezone": 7200,
  "id": 588409,
  "name": "Tallinn",
  "cod": 200
  }
)";
