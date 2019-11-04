#pragma once
#include <string>

std::string tallinn_forecast_response = R"(
{
  "cod": "200",
  "message": 0,
  "cnt": 40,
  "list": [
    {
      "dt": 1572264000,
      "main": {
        "temp": 4.77,
        "temp_min": 4.63,
        "temp_max": 4.77,
        "pressure": 1009,
        "sea_level": 1009,
        "grnd_level": 1007,
        "humidity": 79,
        "temp_kf": 0.14
      },
      "weather": [
        {
          "id": 803,
          "main": "Clouds",
          "description": "broken clouds",
          "icon": "04d"
        }
      ],
      "clouds": {
        "all": 67
      },
      "wind": {
        "speed": 1.39,
        "deg": 236
      },
      "sys": {
        "pod": "d"
      },
      "dt_txt": "2019-10-28 12:00:00"
    },
    {
      "dt": 1572274800,
      "main": {
        "temp": 3.8,
        "temp_min": 3.7,
        "temp_max": 3.8,
        "pressure": 1009,
        "sea_level": 1009,
        "grnd_level": 1007,
        "humidity": 94,
        "temp_kf": 0.1
      },
      "weather": [
        {
          "id": 500,
          "main": "Rain",
          "description": "light rain",
          "icon": "10n"
        }
      ],
      "clouds": {
        "all": 100
      },
      "wind": {
        "speed": 3.04,
        "deg": 63
      },
      "rain": {
        "3h": 1.5
      },
      "sys": {
        "pod": "n"
      },
      "dt_txt": "2019-10-28 15:00:00"
    },
    {
      "dt": 1572285600,
      "main": {
        "temp": 3.65,
        "temp_min": 3.58,
        "temp_max": 3.65,
        "pressure": 1011,
        "sea_level": 1011,
        "grnd_level": 1008,
        "humidity": 91,
        "temp_kf": 0.07
      },
      "weather": [
        {
          "id": 500,
          "main": "Rain",
          "description": "light rain",
          "icon": "10n"
        }
      ],
      "clouds": {
        "all": 100
      },
      "wind": {
        "speed": 4.8,
        "deg": 44
      },
      "rain": {
        "3h": 0.5
      },
      "sys": {
        "pod": "n"
      },
      "dt_txt": "2019-10-28 18:00:00"
    },
    {
      "dt": 1572296400,
      "main": {
        "temp": 3.3,
        "temp_min": 3.27,
        "temp_max": 3.3,
        "pressure": 1011,
        "sea_level": 1011,
        "grnd_level": 1008,
        "humidity": 85,
        "temp_kf": 0.03
      },
      "weather": [
        {
          "id": 600,
          "main": "Snow",
          "description": "light snow",
          "icon": "13n"
        }
      ],
      "clouds": {
        "all": 100
      },
      "wind": {
        "speed": 5.38,
        "deg": 28
      },
      "snow": {
        "3h": 0.13
      },
      "sys": {
        "pod": "n"
      },
      "dt_txt": "2019-10-28 21:00:00"
    },
    {
      "dt": 1572307200,
      "main": {
        "temp": 2.8,
        "temp_min": 2.8,
        "temp_max": 2.8,
        "pressure": 1012,
        "sea_level": 1012,
        "grnd_level": 1010,
        "humidity": 70,
        "temp_kf": 0
      },
      "weather": [
        {
          "id": 600,
          "main": "Snow",
          "description": "light snow",
          "icon": "13n"
        }
      ],
      "clouds": {
        "all": 92
      },
      "wind": {
        "speed": 4.71,
        "deg": 6
      },
      "snow": {
        "3h": 0.13
      },
      "sys": {
        "pod": "n"
      },
      "dt_txt": "2019-10-29 00:00:00"
    },
    {
      "dt": 1572318000,
      "main": {
        "temp": 1.85,
        "temp_min": 1.85,
        "temp_max": 1.85,
        "pressure": 1013,
        "sea_level": 1013,
        "grnd_level": 1010,
        "humidity": 70,
        "temp_kf": 0
      },
      "weather": [
        {
          "id": 803,
          "main": "Clouds",
          "description": "broken clouds",
          "icon": "04n"
        }
      ],
      "clouds": {
        "all": 61
      },
      "wind": {
        "speed": 4.96,
        "deg": 350
      },
      "sys": {
        "pod": "n"
      },
      "dt_txt": "2019-10-29 03:00:00"
    },
    {
      "dt": 1572328800,
      "main": {
        "temp": 1.73,
        "temp_min": 1.73,
        "temp_max": 1.73,
        "pressure": 1014,
        "sea_level": 1014,
        "grnd_level": 1011,
        "humidity": 74,
        "temp_kf": 0
      },
      "weather": [
        {
          "id": 600,
          "main": "Snow",
          "description": "light snow",
          "icon": "13d"
        }
      ],
      "clouds": {
        "all": 78
      },
      "wind": {
        "speed": 5.22,
        "deg": 339
      },
      "snow": {
        "3h": 0.13
      },
      "sys": {
        "pod": "d"
      },
      "dt_txt": "2019-10-29 06:00:00"
    },
    {
      "dt": 1572339600,
      "main": {
        "temp": 1.7,
        "temp_min": 1.7,
        "temp_max": 1.7,
        "pressure": 1015,
        "sea_level": 1015,
        "grnd_level": 1012,
        "humidity": 74,
        "temp_kf": 0
      },
      "weather": [
        {
          "id": 600,
          "main": "Snow",
          "description": "light snow",
          "icon": "13d"
        }
      ],
      "clouds": {
        "all": 100
      },
      "wind": {
        "speed": 5.36,
        "deg": 342
      },
      "snow": {
        "3h": 0.25
      },
      "sys": {
        "pod": "d"
      },
      "dt_txt": "2019-10-29 09:00:00"
    },
    {
      "dt": 1572350400,
      "main": {
        "temp": 2.3,
        "temp_min": 2.3,
        "temp_max": 2.3,
        "pressure": 1016,
        "sea_level": 1016,
        "grnd_level": 1014,
        "humidity": 68,
        "temp_kf": 0
      },
      "weather": [
        {
          "id": 600,
          "main": "Snow",
          "description": "light snow",
          "icon": "13d"
        }
      ],
      "clouds": {
        "all": 100
      },
      "wind": {
        "speed": 6.77,
        "deg": 342
      },
      "snow": {
        "3h": 0.25
      },
      "sys": {
        "pod": "d"
      },
      "dt_txt": "2019-10-29 12:00:00"
    },
    {
      "dt": 1572361200,
      "main": {
        "temp": 2.13,
        "temp_min": 2.13,
        "temp_max": 2.13,
        "pressure": 1017,
        "sea_level": 1017,
        "grnd_level": 1014,
        "humidity": 64,
        "temp_kf": 0
      },
      "weather": [
        {
          "id": 600,
          "main": "Snow",
          "description": "light snow",
          "icon": "13n"
        }
      ],
      "clouds": {
        "all": 73
      },
      "wind": {
        "speed": 8.18,
        "deg": 342
      },
      "snow": {
        "3h": 0.31
      },
      "sys": {
        "pod": "n"
      },
      "dt_txt": "2019-10-29 15:00:00"
    },
    {
      "dt": 1572372000,
      "main": {
        "temp": 1.96,
        "temp_min": 1.96,
        "temp_max": 1.96,
        "pressure": 1019,
        "sea_level": 1019,
        "grnd_level": 1016,
        "humidity": 63,
        "temp_kf": 0
      },
      "weather": [
        {
          "id": 600,
          "main": "Snow",
          "description": "light snow",
          "icon": "13n"
        }
      ],
      "clouds": {
        "all": 54
      },
      "wind": {
        "speed": 8.83,
        "deg": 347
      },
      "snow": {
        "3h": 0.25
      },
      "sys": {
        "pod": "n"
      },
      "dt_txt": "2019-10-29 18:00:00"
    },
    {
      "dt": 1572382800,
      "main": {
        "temp": 1.02,
        "temp_min": 1.02,
        "temp_max": 1.02,
        "pressure": 1021,
        "sea_level": 1021,
        "grnd_level": 1018,
        "humidity": 68,
        "temp_kf": 0
      },
      "weather": [
        {
          "id": 600,
          "main": "Snow",
          "description": "light snow",
          "icon": "13n"
        }
      ],
      "clouds": {
        "all": 76
      },
      "wind": {
        "speed": 8.47,
        "deg": 354
      },
      "snow": {
        "3h": 0.06
      },
      "sys": {
        "pod": "n"
      },
      "dt_txt": "2019-10-29 21:00:00"
    },
    {
      "dt": 1572393600,
      "main": {
        "temp": 1.01,
        "temp_min": 1.01,
        "temp_max": 1.01,
        "pressure": 1023,
        "sea_level": 1023,
        "grnd_level": 1020,
        "humidity": 64,
        "temp_kf": 0
      },
      "weather": [
        {
          "id": 600,
          "main": "Snow",
          "description": "light snow",
          "icon": "13n"
        }
      ],
      "clouds": {
        "all": 81
      },
      "wind": {
        "speed": 6.96,
        "deg": 357
      },
      "snow": {
        "3h": 0.06
      },
      "sys": {
        "pod": "n"
      },
      "dt_txt": "2019-10-30 00:00:00"
    },
    {
      "dt": 1572404400,
      "main": {
        "temp": 0.71,
        "temp_min": 0.71,
        "temp_max": 0.71,
        "pressure": 1024,
        "sea_level": 1024,
        "grnd_level": 1021,
        "humidity": 60,
        "temp_kf": 0
      },
      "weather": [
        {
          "id": 802,
          "main": "Clouds",
          "description": "scattered clouds",
          "icon": "03n"
        }
      ],
      "clouds": {
        "all": 42
      },
      "wind": {
        "speed": 5.96,
        "deg": 346
      },
      "sys": {
        "pod": "n"
      },
      "dt_txt": "2019-10-30 03:00:00"
    },
    {
      "dt": 1572415200,
      "main": {
        "temp": 0.4,
        "temp_min": 0.4,
        "temp_max": 0.4,
        "pressure": 1025,
        "sea_level": 1025,
        "grnd_level": 1022,
        "humidity": 64,
        "temp_kf": 0
      },
      "weather": [
        {
          "id": 801,
          "main": "Clouds",
          "description": "few clouds",
          "icon": "02d"
        }
      ],
      "clouds": {
        "all": 21
      },
      "wind": {
        "speed": 3.98,
        "deg": 337
      },
      "sys": {
        "pod": "d"
      },
      "dt_txt": "2019-10-30 06:00:00"
    },
    {
      "dt": 1572426000,
      "main": {
        "temp": 2.27,
        "temp_min": 2.27,
        "temp_max": 2.27,
        "pressure": 1025,
        "sea_level": 1025,
        "grnd_level": 1022,
        "humidity": 51,
        "temp_kf": 0
      },
      "weather": [
        {
          "id": 801,
          "main": "Clouds",
          "description": "few clouds",
          "icon": "02d"
        }
      ],
      "clouds": {
        "all": 18
      },
      "wind": {
        "speed": 2.64,
        "deg": 311
      },
      "sys": {
        "pod": "d"
      },
      "dt_txt": "2019-10-30 09:00:00"
    },
    {
      "dt": 1572436800,
      "main": {
        "temp": 2.78,
        "temp_min": 2.78,
        "temp_max": 2.78,
        "pressure": 1024,
        "sea_level": 1024,
        "grnd_level": 1021,
        "humidity": 56,
        "temp_kf": 0
      },
      "weather": [
        {
          "id": 802,
          "main": "Clouds",
          "description": "scattered clouds",
          "icon": "03d"
        }
      ],
      "clouds": {
        "all": 47
      },
      "wind": {
        "speed": 3.49,
        "deg": 224
      },
      "sys": {
        "pod": "d"
      },
      "dt_txt": "2019-10-30 12:00:00"
    },
    {
      "dt": 1572447600,
      "main": {
        "temp": -0.18,
        "temp_min": -0.18,
        "temp_max": -0.18,
        "pressure": 1022,
        "sea_level": 1022,
        "grnd_level": 1020,
        "humidity": 94,
        "temp_kf": 0
      },
      "weather": [
        {
          "id": 600,
          "main": "Snow",
          "description": "light snow",
          "icon": "13n"
        }
      ],
      "clouds": {
        "all": 99
      },
      "wind": {
        "speed": 4.3,
        "deg": 183
      },
      "snow": {
        "3h": 0.31
      },
      "sys": {
        "pod": "n"
      },
      "dt_txt": "2019-10-30 15:00:00"
    },
    {
      "dt": 1572458400,
      "main": {
        "temp": 3.57,
        "temp_min": 3.57,
        "temp_max": 3.57,
        "pressure": 1021,
        "sea_level": 1021,
        "grnd_level": 1019,
        "humidity": 89,
        "temp_kf": 0
      },
      "weather": [
        {
          "id": 500,
          "main": "Rain",
          "description": "light rain",
          "icon": "10n"
        }
      ],
      "clouds": {
        "all": 99
      },
      "wind": {
        "speed": 3.4,
        "deg": 270
      },
      "rain": {
        "3h": 0.5
      },
      "sys": {
        "pod": "n"
      },
      "dt_txt": "2019-10-30 18:00:00"
    },
    {
      "dt": 1572469200,
      "main": {
        "temp": 3.55,
        "temp_min": 3.55,
        "temp_max": 3.55,
        "pressure": 1020,
        "sea_level": 1020,
        "grnd_level": 1018,
        "humidity": 85,
        "temp_kf": 0
      },
      "weather": [
        {
          "id": 500,
          "main": "Rain",
          "description": "light rain",
          "icon": "10n"
        }
      ],
      "clouds": {
        "all": 100
      },
      "wind": {
        "speed": 3.25,
        "deg": 224
      },
      "rain": {
        "3h": 0.25
      },
      "sys": {
        "pod": "n"
      },
      "dt_txt": "2019-10-30 21:00:00"
    },
    {
      "dt": 1572480000,
      "main": {
        "temp": 2.5,
        "temp_min": 2.5,
        "temp_max": 2.5,
        "pressure": 1019,
        "sea_level": 1019,
        "grnd_level": 1016,
        "humidity": 86,
        "temp_kf": 0
      },
      "weather": [
        {
          "id": 804,
          "main": "Clouds",
          "description": "overcast clouds",
          "icon": "04n"
        }
      ],
      "clouds": {
        "all": 93
      },
      "wind": {
        "speed": 4.08,
        "deg": 228
      },
      "sys": {
        "pod": "n"
      },
      "dt_txt": "2019-10-31 00:00:00"
    },
    {
      "dt": 1572490800,
      "main": {
        "temp": 3.5,
        "temp_min": 3.5,
        "temp_max": 3.5,
        "pressure": 1017,
        "sea_level": 1017,
        "grnd_level": 1014,
        "humidity": 84,
        "temp_kf": 0
      },
      "weather": [
        {
          "id": 804,
          "main": "Clouds",
          "description": "overcast clouds",
          "icon": "04n"
        }
      ],
      "clouds": {
        "all": 100
      },
      "wind": {
        "speed": 4.79,
        "deg": 233
      },
      "sys": {
        "pod": "n"
      },
      "dt_txt": "2019-10-31 03:00:00"
    },
    {
      "dt": 1572501600,
      "main": {
        "temp": 3.9,
        "temp_min": 3.9,
        "temp_max": 3.9,
        "pressure": 1015,
        "sea_level": 1015,
        "grnd_level": 1013,
        "humidity": 85,
        "temp_kf": 0
      },
      "weather": [
        {
          "id": 804,
          "main": "Clouds",
          "description": "overcast clouds",
          "icon": "04d"
        }
      ],
      "clouds": {
        "all": 100
      },
      "wind": {
        "speed": 5.08,
        "deg": 238
      },
      "sys": {
        "pod": "d"
      },
      "dt_txt": "2019-10-31 06:00:00"
    },
    {
      "dt": 1572512400,
      "main": {
        "temp": 5.57,
        "temp_min": 5.57,
        "temp_max": 5.57,
        "pressure": 1014,
        "sea_level": 1014,
        "grnd_level": 1012,
        "humidity": 85,
        "temp_kf": 0
      },
      "weather": [
        {
          "id": 500,
          "main": "Rain",
          "description": "light rain",
          "icon": "10d"
        }
      ],
      "clouds": {
        "all": 100
      },
      "wind": {
        "speed": 7.49,
        "deg": 278
      },
      "rain": {
        "3h": 0.56
      },
      "sys": {
        "pod": "d"
      },
      "dt_txt": "2019-10-31 09:00:00"
    },
    {
      "dt": 1572523200,
      "main": {
        "temp": 6.49,
        "temp_min": 6.49,
        "temp_max": 6.49,
        "pressure": 1013,
        "sea_level": 1013,
        "grnd_level": 1010,
        "humidity": 75,
        "temp_kf": 0
      },
      "weather": [
        {
          "id": 500,
          "main": "Rain",
          "description": "light rain",
          "icon": "10d"
        }
      ],
      "clouds": {
        "all": 100
      },
      "wind": {
        "speed": 6.68,
        "deg": 293
      },
      "rain": {
        "3h": 0.63
      },
      "sys": {
        "pod": "d"
      },
      "dt_txt": "2019-10-31 12:00:00"
    },
    {
      "dt": 1572534000,
      "main": {
        "temp": 5.89,
        "temp_min": 5.89,
        "temp_max": 5.89,
        "pressure": 1012,
        "sea_level": 1012,
        "grnd_level": 1010,
        "humidity": 75,
        "temp_kf": 0
      },
      "weather": [
        {
          "id": 500,
          "main": "Rain",
          "description": "light rain",
          "icon": "10n"
        }
      ],
      "clouds": {
        "all": 40
      },
      "wind": {
        "speed": 7.83,
        "deg": 295
      },
      "rain": {
        "3h": 0.44
      },
      "sys": {
        "pod": "n"
      },
      "dt_txt": "2019-10-31 15:00:00"
    },
    {
      "dt": 1572544800,
      "main": {
        "temp": 5.82,
        "temp_min": 5.82,
        "temp_max": 5.82,
        "pressure": 1013,
        "sea_level": 1013,
        "grnd_level": 1010,
        "humidity": 69,
        "temp_kf": 0
      },
      "weather": [
        {
          "id": 500,
          "main": "Rain",
          "description": "light rain",
          "icon": "10n"
        }
      ],
      "clouds": {
        "all": 51
      },
      "wind": {
        "speed": 9.36,
        "deg": 310
      },
      "rain": {
        "3h": 0.25
      },
      "sys": {
        "pod": "n"
      },
      "dt_txt": "2019-10-31 18:00:00"
    },
    {
      "dt": 1572555600,
      "main": {
        "temp": 4.71,
        "temp_min": 4.71,
        "temp_max": 4.71,
        "pressure": 1014,
        "sea_level": 1014,
        "grnd_level": 1011,
        "humidity": 73,
        "temp_kf": 0
      },
      "weather": [
        {
          "id": 500,
          "main": "Rain",
          "description": "light rain",
          "icon": "10n"
        }
      ],
      "clouds": {
        "all": 39
      },
      "wind": {
        "speed": 8.37,
        "deg": 319
      },
      "rain": {
        "3h": 0.19
      },
      "sys": {
        "pod": "n"
      },
      "dt_txt": "2019-10-31 21:00:00"
    },
    {
      "dt": 1572566400,
      "main": {
        "temp": 3.65,
        "temp_min": 3.65,
        "temp_max": 3.65,
        "pressure": 1015,
        "sea_level": 1015,
        "grnd_level": 1012,
        "humidity": 71,
        "temp_kf": 0
      },
      "weather": [
        {
          "id": 801,
          "main": "Clouds",
          "description": "few clouds",
          "icon": "02n"
        }
      ],
      "clouds": {
        "all": 20
      },
      "wind": {
        "speed": 7.79,
        "deg": 328
      },
      "sys": {
        "pod": "n"
      },
      "dt_txt": "2019-11-01 00:00:00"
    },
    {
      "dt": 1572577200,
      "main": {
        "temp": 2,
        "temp_min": 2,
        "temp_max": 2,
        "pressure": 1015,
        "sea_level": 1015,
        "grnd_level": 1013,
        "humidity": 74,
        "temp_kf": 0
      },
      "weather": [
        {
          "id": 800,
          "main": "Clear",
          "description": "clear sky",
          "icon": "01n"
        }
      ],
      "clouds": {
        "all": 0
      },
      "wind": {
        "speed": 5.76,
        "deg": 336
      },
      "sys": {
        "pod": "n"
      },
      "dt_txt": "2019-11-01 03:00:00"
    },
    {
      "dt": 1572588000,
      "main": {
        "temp": 0.83,
        "temp_min": 0.83,
        "temp_max": 0.83,
        "pressure": 1016,
        "sea_level": 1016,
        "grnd_level": 1014,
        "humidity": 78,
        "temp_kf": 0
      },
      "weather": [
        {
          "id": 802,
          "main": "Clouds",
          "description": "scattered clouds",
          "icon": "03d"
        }
      ],
      "clouds": {
        "all": 33
      },
      "wind": {
        "speed": 3.11,
        "deg": 341
      },
      "sys": {
        "pod": "d"
      },
      "dt_txt": "2019-11-01 06:00:00"
    },
    {
      "dt": 1572598800,
      "main": {
        "temp": 2.18,
        "temp_min": 2.18,
        "temp_max": 2.18,
        "pressure": 1017,
        "sea_level": 1017,
        "grnd_level": 1015,
        "humidity": 72,
        "temp_kf": 0
      },
      "weather": [
        {
          "id": 800,
          "main": "Clear",
          "description": "clear sky",
          "icon": "01d"
        }
      ],
      "clouds": {
        "all": 0
      },
      "wind": {
        "speed": 2.46,
        "deg": 326
      },
      "sys": {
        "pod": "d"
      },
      "dt_txt": "2019-11-01 09:00:00"
    },
    {
      "dt": 1572609600,
      "main": {
        "temp": 2.51,
        "temp_min": 2.51,
        "temp_max": 2.51,
        "pressure": 1017,
        "sea_level": 1017,
        "grnd_level": 1014,
        "humidity": 71,
        "temp_kf": 0
      },
      "weather": [
        {
          "id": 801,
          "main": "Clouds",
          "description": "few clouds",
          "icon": "02d"
        }
      ],
      "clouds": {
        "all": 15
      },
      "wind": {
        "speed": 1.53,
        "deg": 292
      },
      "sys": {
        "pod": "d"
      },
      "dt_txt": "2019-11-01 12:00:00"
    },
    {
      "dt": 1572620400,
      "main": {
        "temp": 1.49,
        "temp_min": 1.49,
        "temp_max": 1.49,
        "pressure": 1016,
        "sea_level": 1016,
        "grnd_level": 1014,
        "humidity": 77,
        "temp_kf": 0
      },
      "weather": [
        {
          "id": 804,
          "main": "Clouds",
          "description": "overcast clouds",
          "icon": "04n"
        }
      ],
      "clouds": {
        "all": 100
      },
      "wind": {
        "speed": 0.15,
        "deg": 215
      },
      "sys": {
        "pod": "n"
      },
      "dt_txt": "2019-11-01 15:00:00"
    },
    {
      "dt": 1572631200,
      "main": {
        "temp": 1.45,
        "temp_min": 1.45,
        "temp_max": 1.45,
        "pressure": 1016,
        "sea_level": 1016,
        "grnd_level": 1013,
        "humidity": 84,
        "temp_kf": 0
      },
      "weather": [
        {
          "id": 804,
          "main": "Clouds",
          "description": "overcast clouds",
          "icon": "04n"
        }
      ],
      "clouds": {
        "all": 100
      },
      "wind": {
        "speed": 2.47,
        "deg": 142
      },
      "sys": {
        "pod": "n"
      },
      "dt_txt": "2019-11-01 18:00:00"
    },
    {
      "dt": 1572642000,
      "main": {
        "temp": 1.83,
        "temp_min": 1.83,
        "temp_max": 1.83,
        "pressure": 1014,
        "sea_level": 1014,
        "grnd_level": 1012,
        "humidity": 88,
        "temp_kf": 0
      },
      "weather": [
        {
          "id": 804,
          "main": "Clouds",
          "description": "overcast clouds",
          "icon": "04n"
        }
      ],
      "clouds": {
        "all": 100
      },
      "wind": {
        "speed": 3.56,
        "deg": 151
      },
      "sys": {
        "pod": "n"
      },
      "dt_txt": "2019-11-01 21:00:00"
    },
    {
      "dt": 1572652800,
      "main": {
        "temp": 1.86,
        "temp_min": 1.86,
        "temp_max": 1.86,
        "pressure": 1013,
        "sea_level": 1013,
        "grnd_level": 1011,
        "humidity": 96,
        "temp_kf": 0
      },
      "weather": [
        {
          "id": 600,
          "main": "Snow",
          "description": "light snow",
          "icon": "13n"
        }
      ],
      "clouds": {
        "all": 100
      },
      "wind": {
        "speed": 4.22,
        "deg": 171
      },
      "snow": {
        "3h": 0.38
      },
      "sys": {
        "pod": "n"
      },
      "dt_txt": "2019-11-02 00:00:00"
    },
    {
      "dt": 1572663600,
      "main": {
        "temp": 2.46,
        "temp_min": 2.46,
        "temp_max": 2.46,
        "pressure": 1012,
        "sea_level": 1012,
        "grnd_level": 1009,
        "humidity": 97,
        "temp_kf": 0
      },
      "weather": [
        {
          "id": 500,
          "main": "Rain",
          "description": "light rain",
          "icon": "10n"
        }
      ],
      "clouds": {
        "all": 100
      },
      "wind": {
        "speed": 4.5,
        "deg": 122
      },
      "rain": {
        "3h": 2
      },
      "sys": {
        "pod": "n"
      },
      "dt_txt": "2019-11-02 03:00:00"
    },
    {
      "dt": 1572674400,
      "main": {
        "temp": 3.24,
        "temp_min": 3.24,
        "temp_max": 3.24,
        "pressure": 1011,
        "sea_level": 1011,
        "grnd_level": 1008,
        "humidity": 95,
        "temp_kf": 0
      },
      "weather": [
        {
          "id": 500,
          "main": "Rain",
          "description": "light rain",
          "icon": "10d"
        }
      ],
      "clouds": {
        "all": 100
      },
      "wind": {
        "speed": 4.49,
        "deg": 147
      },
      "rain": {
        "3h": 0.38
      },
      "sys": {
        "pod": "d"
      },
      "dt_txt": "2019-11-02 06:00:00"
    },
    {
      "dt": 1572685200,
      "main": {
        "temp": 4.01,
        "temp_min": 4.01,
        "temp_max": 4.01,
        "pressure": 1011,
        "sea_level": 1011,
        "grnd_level": 1008,
        "humidity": 92,
        "temp_kf": 0
      },
      "weather": [
        {
          "id": 804,
          "main": "Clouds",
          "description": "overcast clouds",
          "icon": "04d"
        }
      ],
      "clouds": {
        "all": 100
      },
      "wind": {
        "speed": 4.24,
        "deg": 141
      },
      "sys": {
        "pod": "d"
      },
      "dt_txt": "2019-11-02 09:00:00"
    }
  ],
  "city": {
    "id": 588409,
    "name": "Tallinn",
    "coord": {
      "lat": 59.4372,
      "lon": 24.7454
    },
    "country": "EE",
    "population": 9999,
    "timezone": 7200,
    "sunrise": 1572240571,
    "sunset": 1572273596
  }
}
)";
