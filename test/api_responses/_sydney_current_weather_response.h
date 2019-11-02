#pragma once
#include <string>

std::string sydney_current_weather_response = R"(
{
    "base": "stations",
    "clouds": {
        "all": 0
    },
    "cod": 200,
    "coord": {
        "lat": -33.85,
        "lon": 151.22
    },
    "dt": 1572710055,
    "id": 2147714,
    "main": {
        "humidity": 82,
        "pressure": 1013,
        "temp": 17.62,
        "temp_max": 19,
        "temp_min": 16.11
    },
    "name": "Sydney",
    "sys": {
        "country": "AU",
        "id": 9600,
        "sunrise": 1572720809,
        "sunset": 1572769427,
        "type": 1
    },
    "timezone": 39600,
    "visibility": 10000,
    "weather": [
        {
            "description": "clear sky",
            "icon": "01n",
            "id": 800,
            "main": "Clear"
        }
    ],
    "wind": {
        "deg": 350,
        "speed": 1.5
    }
}
)";
