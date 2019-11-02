
#pragma once
#include <string>

std::string sydney_forecast_response = R"(
{
    "city": {
        "coord": {
            "lat": -33.8549,
            "lon": 151.2165
        },
        "country": "AU",
        "id": 2147714,
        "name": "Sydney",
        "population": 1000000,
        "sunrise": 1572720809,
        "sunset": 1572769428,
        "timezone": 39600
    },
    "cnt": 40,
    "cod": "200",
    "list": [
        {
            "clouds": {
                "all": 14
            },
            "dt": 1572717600,
            "dt_txt": "2019-11-02 18:00:00",
            "main": {
                "grnd_level": 1003,
                "humidity": 67,
                "pressure": 1013,
                "sea_level": 1013,
                "temp": 16.8,
                "temp_kf": -1.82,
                "temp_max": 18.62,
                "temp_min": 16.8
            },
            "sys": {
                "pod": "n"
            },
            "weather": [
                {
                    "description": "few clouds",
                    "icon": "02n",
                    "id": 801,
                    "main": "Clouds"
                }
            ],
            "wind": {
                "deg": 314,
                "speed": 2.06
            }
        },
        {
            "clouds": {
                "all": 33
            },
            "dt": 1572728400,
            "dt_txt": "2019-11-02 21:00:00",
            "main": {
                "grnd_level": 1004,
                "humidity": 44,
                "pressure": 1014,
                "sea_level": 1014,
                "temp": 23.25,
                "temp_kf": -1.37,
                "temp_max": 24.61,
                "temp_min": 23.25
            },
            "sys": {
                "pod": "d"
            },
            "weather": [
                {
                    "description": "scattered clouds",
                    "icon": "03d",
                    "id": 802,
                    "main": "Clouds"
                }
            ],
            "wind": {
                "deg": 330,
                "speed": 4.47
            }
        },
        {
            "clouds": {
                "all": 34
            },
            "dt": 1572739200,
            "dt_txt": "2019-11-03 00:00:00",
            "main": {
                "grnd_level": 1003,
                "humidity": 32,
                "pressure": 1013,
                "sea_level": 1013,
                "temp": 30,
                "temp_kf": -0.91,
                "temp_max": 30.91,
                "temp_min": 30
            },
            "sys": {
                "pod": "d"
            },
            "weather": [
                {
                    "description": "scattered clouds",
                    "icon": "03d",
                    "id": 802,
                    "main": "Clouds"
                }
            ],
            "wind": {
                "deg": 340,
                "speed": 5.07
            }
        },
        {
            "clouds": {
                "all": 72
            },
            "dt": 1572750000,
            "dt_txt": "2019-11-03 03:00:00",
            "main": {
                "grnd_level": 1000,
                "humidity": 45,
                "pressure": 1011,
                "sea_level": 1011,
                "temp": 27.27,
                "temp_kf": -0.46,
                "temp_max": 27.72,
                "temp_min": 27.27
            },
            "rain": {
                "3h": 0.81
            },
            "sys": {
                "pod": "d"
            },
            "weather": [
                {
                    "description": "light rain",
                    "icon": "10d",
                    "id": 500,
                    "main": "Rain"
                }
            ],
            "wind": {
                "deg": 4,
                "speed": 3.33
            }
        },
        {
            "clouds": {
                "all": 86
            },
            "dt": 1572760800,
            "dt_txt": "2019-11-03 06:00:00",
            "main": {
                "grnd_level": 1000,
                "humidity": 78,
                "pressure": 1010,
                "sea_level": 1010,
                "temp": 21.43,
                "temp_kf": 0,
                "temp_max": 21.43,
                "temp_min": 21.43
            },
            "rain": {
                "3h": 7.63
            },
            "sys": {
                "pod": "d"
            },
            "weather": [
                {
                    "description": "moderate rain",
                    "icon": "10d",
                    "id": 501,
                    "main": "Rain"
                }
            ],
            "wind": {
                "deg": 346,
                "speed": 1.8
            }
        },
        {
            "clouds": {
                "all": 100
            },
            "dt": 1572771600,
            "dt_txt": "2019-11-03 09:00:00",
            "main": {
                "grnd_level": 1002,
                "humidity": 77,
                "pressure": 1012,
                "sea_level": 1012,
                "temp": 20.55,
                "temp_kf": 0,
                "temp_max": 20.55,
                "temp_min": 20.55
            },
            "rain": {
                "3h": 0.31
            },
            "sys": {
                "pod": "n"
            },
            "weather": [
                {
                    "description": "light rain",
                    "icon": "10n",
                    "id": 500,
                    "main": "Rain"
                }
            ],
            "wind": {
                "deg": 35,
                "speed": 1.96
            }
        },
        {
            "clouds": {
                "all": 100
            },
            "dt": 1572782400,
            "dt_txt": "2019-11-03 12:00:00",
            "main": {
                "grnd_level": 1003,
                "humidity": 88,
                "pressure": 1013,
                "sea_level": 1013,
                "temp": 18.38,
                "temp_kf": 0,
                "temp_max": 18.38,
                "temp_min": 18.38
            },
            "rain": {
                "3h": 6.44
            },
            "sys": {
                "pod": "n"
            },
            "weather": [
                {
                    "description": "moderate rain",
                    "icon": "10n",
                    "id": 501,
                    "main": "Rain"
                }
            ],
            "wind": {
                "deg": 216,
                "speed": 4.47
            }
        },
        {
            "clouds": {
                "all": 100
            },
            "dt": 1572793200,
            "dt_txt": "2019-11-03 15:00:00",
            "main": {
                "grnd_level": 1004,
                "humidity": 86,
                "pressure": 1012,
                "sea_level": 1012,
                "temp": 15.63,
                "temp_kf": 0,
                "temp_max": 15.63,
                "temp_min": 15.63
            },
            "rain": {
                "3h": 3.56
            },
            "sys": {
                "pod": "n"
            },
            "weather": [
                {
                    "description": "moderate rain",
                    "icon": "10n",
                    "id": 501,
                    "main": "Rain"
                }
            ],
            "wind": {
                "deg": 263,
                "speed": 1.51
            }
        },
        {
            "clouds": {
                "all": 92
            },
            "dt": 1572804000,
            "dt_txt": "2019-11-03 18:00:00",
            "main": {
                "grnd_level": 1004,
                "humidity": 86,
                "pressure": 1013,
                "sea_level": 1013,
                "temp": 15.19,
                "temp_kf": 0,
                "temp_max": 15.19,
                "temp_min": 15.19
            },
            "rain": {
                "3h": 0.25
            },
            "sys": {
                "pod": "n"
            },
            "weather": [
                {
                    "description": "light rain",
                    "icon": "10n",
                    "id": 500,
                    "main": "Rain"
                }
            ],
            "wind": {
                "deg": 262,
                "speed": 1.87
            }
        },
        {
            "clouds": {
                "all": 14
            },
            "dt": 1572814800,
            "dt_txt": "2019-11-03 21:00:00",
            "main": {
                "grnd_level": 1005,
                "humidity": 75,
                "pressure": 1015,
                "sea_level": 1015,
                "temp": 17.4,
                "temp_kf": 0,
                "temp_max": 17.4,
                "temp_min": 17.4
            },
            "sys": {
                "pod": "d"
            },
            "weather": [
                {
                    "description": "few clouds",
                    "icon": "02d",
                    "id": 801,
                    "main": "Clouds"
                }
            ],
            "wind": {
                "deg": 262,
                "speed": 2.21
            }
        },
        {
            "clouds": {
                "all": 7
            },
            "dt": 1572825600,
            "dt_txt": "2019-11-04 00:00:00",
            "main": {
                "grnd_level": 1005,
                "humidity": 40,
                "pressure": 1015,
                "sea_level": 1015,
                "temp": 24.75,
                "temp_kf": 0,
                "temp_max": 24.75,
                "temp_min": 24.75
            },
            "sys": {
                "pod": "d"
            },
            "weather": [
                {
                    "description": "clear sky",
                    "icon": "01d",
                    "id": 800,
                    "main": "Clear"
                }
            ],
            "wind": {
                "deg": 271,
                "speed": 2.63
            }
        },
        {
            "clouds": {
                "all": 52
            },
            "dt": 1572836400,
            "dt_txt": "2019-11-04 03:00:00",
            "main": {
                "grnd_level": 1004,
                "humidity": 49,
                "pressure": 1013,
                "sea_level": 1013,
                "temp": 22.51,
                "temp_kf": 0,
                "temp_max": 22.51,
                "temp_min": 22.51
            },
            "sys": {
                "pod": "d"
            },
            "weather": [
                {
                    "description": "broken clouds",
                    "icon": "04d",
                    "id": 803,
                    "main": "Clouds"
                }
            ],
            "wind": {
                "deg": 116,
                "speed": 4.05
            }
        },
        {
            "clouds": {
                "all": 31
            },
            "dt": 1572847200,
            "dt_txt": "2019-11-04 06:00:00",
            "main": {
                "grnd_level": 1003,
                "humidity": 52,
                "pressure": 1012,
                "sea_level": 1012,
                "temp": 22.33,
                "temp_kf": 0,
                "temp_max": 22.33,
                "temp_min": 22.33
            },
            "sys": {
                "pod": "d"
            },
            "weather": [
                {
                    "description": "scattered clouds",
                    "icon": "03d",
                    "id": 802,
                    "main": "Clouds"
                }
            ],
            "wind": {
                "deg": 91,
                "speed": 4.56
            }
        },
        {
            "clouds": {
                "all": 73
            },
            "dt": 1572858000,
            "dt_txt": "2019-11-04 09:00:00",
            "main": {
                "grnd_level": 1004,
                "humidity": 77,
                "pressure": 1013,
                "sea_level": 1013,
                "temp": 18.37,
                "temp_kf": 0,
                "temp_max": 18.37,
                "temp_min": 18.37
            },
            "rain": {
                "3h": 0.44
            },
            "sys": {
                "pod": "n"
            },
            "weather": [
                {
                    "description": "light rain",
                    "icon": "10n",
                    "id": 500,
                    "main": "Rain"
                }
            ],
            "wind": {
                "deg": 37,
                "speed": 1.87
            }
        },
        {
            "clouds": {
                "all": 44
            },
            "dt": 1572868800,
            "dt_txt": "2019-11-04 12:00:00",
            "main": {
                "grnd_level": 1004,
                "humidity": 83,
                "pressure": 1014,
                "sea_level": 1014,
                "temp": 15.99,
                "temp_kf": 0,
                "temp_max": 15.99,
                "temp_min": 15.99
            },
            "rain": {
                "3h": 0.94
            },
            "sys": {
                "pod": "n"
            },
            "weather": [
                {
                    "description": "light rain",
                    "icon": "10n",
                    "id": 500,
                    "main": "Rain"
                }
            ],
            "wind": {
                "deg": 312,
                "speed": 2.13
            }
        },
        {
            "clouds": {
                "all": 100
            },
            "dt": 1572879600,
            "dt_txt": "2019-11-04 15:00:00",
            "main": {
                "grnd_level": 1004,
                "humidity": 74,
                "pressure": 1013,
                "sea_level": 1013,
                "temp": 13.39,
                "temp_kf": 0,
                "temp_max": 13.39,
                "temp_min": 13.39
            },
            "rain": {
                "3h": 0.75
            },
            "sys": {
                "pod": "n"
            },
            "weather": [
                {
                    "description": "light rain",
                    "icon": "10n",
                    "id": 500,
                    "main": "Rain"
                }
            ],
            "wind": {
                "deg": 231,
                "speed": 2.67
            }
        },
        {
            "clouds": {
                "all": 71
            },
            "dt": 1572890400,
            "dt_txt": "2019-11-04 18:00:00",
            "main": {
                "grnd_level": 1004,
                "humidity": 72,
                "pressure": 1013,
                "sea_level": 1013,
                "temp": 10.95,
                "temp_kf": 0,
                "temp_max": 10.95,
                "temp_min": 10.95
            },
            "sys": {
                "pod": "n"
            },
            "weather": [
                {
                    "description": "broken clouds",
                    "icon": "04n",
                    "id": 803,
                    "main": "Clouds"
                }
            ],
            "wind": {
                "deg": 234,
                "speed": 2.65
            }
        },
        {
            "clouds": {
                "all": 33
            },
            "dt": 1572901200,
            "dt_txt": "2019-11-04 21:00:00",
            "main": {
                "grnd_level": 1006,
                "humidity": 70,
                "pressure": 1015,
                "sea_level": 1015,
                "temp": 14.35,
                "temp_kf": 0,
                "temp_max": 14.35,
                "temp_min": 14.35
            },
            "sys": {
                "pod": "d"
            },
            "weather": [
                {
                    "description": "scattered clouds",
                    "icon": "03d",
                    "id": 802,
                    "main": "Clouds"
                }
            ],
            "wind": {
                "deg": 200,
                "speed": 4.22
            }
        },
        {
            "clouds": {
                "all": 20
            },
            "dt": 1572912000,
            "dt_txt": "2019-11-05 00:00:00",
            "main": {
                "grnd_level": 1006,
                "humidity": 57,
                "pressure": 1015,
                "sea_level": 1015,
                "temp": 17.57,
                "temp_kf": 0,
                "temp_max": 17.57,
                "temp_min": 17.57
            },
            "rain": {
                "3h": 0.88
            },
            "sys": {
                "pod": "d"
            },
            "weather": [
                {
                    "description": "light rain",
                    "icon": "10d",
                    "id": 500,
                    "main": "Rain"
                }
            ],
            "wind": {
                "deg": 174,
                "speed": 6.71
            }
        },
        {
            "clouds": {
                "all": 11
            },
            "dt": 1572922800,
            "dt_txt": "2019-11-05 03:00:00",
            "main": {
                "grnd_level": 1006,
                "humidity": 51,
                "pressure": 1014,
                "sea_level": 1014,
                "temp": 18.35,
                "temp_kf": 0,
                "temp_max": 18.35,
                "temp_min": 18.35
            },
            "rain": {
                "3h": 1.19
            },
            "sys": {
                "pod": "d"
            },
            "weather": [
                {
                    "description": "light rain",
                    "icon": "10d",
                    "id": 500,
                    "main": "Rain"
                }
            ],
            "wind": {
                "deg": 168,
                "speed": 6.8
            }
        },
        {
            "clouds": {
                "all": 6
            },
            "dt": 1572933600,
            "dt_txt": "2019-11-05 06:00:00",
            "main": {
                "grnd_level": 1004,
                "humidity": 58,
                "pressure": 1013,
                "sea_level": 1013,
                "temp": 16.88,
                "temp_kf": 0,
                "temp_max": 16.88,
                "temp_min": 16.88
            },
            "sys": {
                "pod": "d"
            },
            "weather": [
                {
                    "description": "clear sky",
                    "icon": "01d",
                    "id": 800,
                    "main": "Clear"
                }
            ],
            "wind": {
                "deg": 156,
                "speed": 6.38
            }
        },
        {
            "clouds": {
                "all": 16
            },
            "dt": 1572944400,
            "dt_txt": "2019-11-05 09:00:00",
            "main": {
                "grnd_level": 1006,
                "humidity": 78,
                "pressure": 1016,
                "sea_level": 1016,
                "temp": 13.38,
                "temp_kf": 0,
                "temp_max": 13.38,
                "temp_min": 13.38
            },
            "sys": {
                "pod": "n"
            },
            "weather": [
                {
                    "description": "few clouds",
                    "icon": "02n",
                    "id": 801,
                    "main": "Clouds"
                }
            ],
            "wind": {
                "deg": 153,
                "speed": 2.62
            }
        },
        {
            "clouds": {
                "all": 31
            },
            "dt": 1572955200,
            "dt_txt": "2019-11-05 12:00:00",
            "main": {
                "grnd_level": 1007,
                "humidity": 84,
                "pressure": 1016,
                "sea_level": 1016,
                "temp": 11.86,
                "temp_kf": 0,
                "temp_max": 11.86,
                "temp_min": 11.86
            },
            "sys": {
                "pod": "n"
            },
            "weather": [
                {
                    "description": "scattered clouds",
                    "icon": "03n",
                    "id": 802,
                    "main": "Clouds"
                }
            ],
            "wind": {
                "deg": 248,
                "speed": 1.76
            }
        },
        {
            "clouds": {
                "all": 32
            },
            "dt": 1572966000,
            "dt_txt": "2019-11-05 15:00:00",
            "main": {
                "grnd_level": 1005,
                "humidity": 86,
                "pressure": 1015,
                "sea_level": 1015,
                "temp": 10.6,
                "temp_kf": 0,
                "temp_max": 10.6,
                "temp_min": 10.6
            },
            "sys": {
                "pod": "n"
            },
            "weather": [
                {
                    "description": "scattered clouds",
                    "icon": "03n",
                    "id": 802,
                    "main": "Clouds"
                }
            ],
            "wind": {
                "deg": 246,
                "speed": 1.71
            }
        },
        {
            "clouds": {
                "all": 16
            },
            "dt": 1572976800,
            "dt_txt": "2019-11-05 18:00:00",
            "main": {
                "grnd_level": 1004,
                "humidity": 90,
                "pressure": 1014,
                "sea_level": 1014,
                "temp": 9.72,
                "temp_kf": 0,
                "temp_max": 9.72,
                "temp_min": 9.72
            },
            "sys": {
                "pod": "n"
            },
            "weather": [
                {
                    "description": "few clouds",
                    "icon": "02n",
                    "id": 801,
                    "main": "Clouds"
                }
            ],
            "wind": {
                "deg": 280,
                "speed": 1.79
            }
        },
        {
            "clouds": {
                "all": 0
            },
            "dt": 1572987600,
            "dt_txt": "2019-11-05 21:00:00",
            "main": {
                "grnd_level": 1004,
                "humidity": 67,
                "pressure": 1013,
                "sea_level": 1013,
                "temp": 13.45,
                "temp_kf": 0,
                "temp_max": 13.45,
                "temp_min": 13.45
            },
            "sys": {
                "pod": "d"
            },
            "weather": [
                {
                    "description": "clear sky",
                    "icon": "01d",
                    "id": 800,
                    "main": "Clear"
                }
            ],
            "wind": {
                "deg": 294,
                "speed": 2.79
            }
        },
        {
            "clouds": {
                "all": 2
            },
            "dt": 1572998400,
            "dt_txt": "2019-11-06 00:00:00",
            "main": {
                "grnd_level": 1001,
                "humidity": 23,
                "pressure": 1011,
                "sea_level": 1011,
                "temp": 21.93,
                "temp_kf": 0,
                "temp_max": 21.93,
                "temp_min": 21.93
            },
            "sys": {
                "pod": "d"
            },
            "weather": [
                {
                    "description": "clear sky",
                    "icon": "01d",
                    "id": 800,
                    "main": "Clear"
                }
            ],
            "wind": {
                "deg": 318,
                "speed": 3.35
            }
        },
        {
            "clouds": {
                "all": 0
            },
            "dt": 1573009200,
            "dt_txt": "2019-11-06 03:00:00",
            "main": {
                "grnd_level": 997,
                "humidity": 14,
                "pressure": 1008,
                "sea_level": 1008,
                "temp": 28.46,
                "temp_kf": 0,
                "temp_max": 28.46,
                "temp_min": 28.46
            },
            "sys": {
                "pod": "d"
            },
            "weather": [
                {
                    "description": "clear sky",
                    "icon": "01d",
                    "id": 800,
                    "main": "Clear"
                }
            ],
            "wind": {
                "deg": 264,
                "speed": 3.16
            }
        },
        {
            "clouds": {
                "all": 0
            },
            "dt": 1573020000,
            "dt_txt": "2019-11-06 06:00:00",
            "main": {
                "grnd_level": 996,
                "humidity": 19,
                "pressure": 1005,
                "sea_level": 1005,
                "temp": 27.17,
                "temp_kf": 0,
                "temp_max": 27.17,
                "temp_min": 27.17
            },
            "sys": {
                "pod": "d"
            },
            "weather": [
                {
                    "description": "clear sky",
                    "icon": "01d",
                    "id": 800,
                    "main": "Clear"
                }
            ],
            "wind": {
                "deg": 260,
                "speed": 3.66
            }
        },
        {
            "clouds": {
                "all": 0
            },
            "dt": 1573030800,
            "dt_txt": "2019-11-06 09:00:00",
            "main": {
                "grnd_level": 997,
                "humidity": 39,
                "pressure": 1007,
                "sea_level": 1007,
                "temp": 19.75,
                "temp_kf": 0,
                "temp_max": 19.75,
                "temp_min": 19.75
            },
            "sys": {
                "pod": "n"
            },
            "weather": [
                {
                    "description": "clear sky",
                    "icon": "01n",
                    "id": 800,
                    "main": "Clear"
                }
            ],
            "wind": {
                "deg": 290,
                "speed": 1.57
            }
        },
        {
            "clouds": {
                "all": 0
            },
            "dt": 1573041600,
            "dt_txt": "2019-11-06 12:00:00",
            "main": {
                "grnd_level": 998,
                "humidity": 40,
                "pressure": 1008,
                "sea_level": 1008,
                "temp": 17.05,
                "temp_kf": 0,
                "temp_max": 17.05,
                "temp_min": 17.05
            },
            "sys": {
                "pod": "n"
            },
            "weather": [
                {
                    "description": "clear sky",
                    "icon": "01n",
                    "id": 800,
                    "main": "Clear"
                }
            ],
            "wind": {
                "deg": 273,
                "speed": 1.94
            }
        },
        {
            "clouds": {
                "all": 0
            },
            "dt": 1573052400,
            "dt_txt": "2019-11-06 15:00:00",
            "main": {
                "grnd_level": 996,
                "humidity": 44,
                "pressure": 1006,
                "sea_level": 1006,
                "temp": 15.41,
                "temp_kf": 0,
                "temp_max": 15.41,
                "temp_min": 15.41
            },
            "sys": {
                "pod": "n"
            },
            "weather": [
                {
                    "description": "clear sky",
                    "icon": "01n",
                    "id": 800,
                    "main": "Clear"
                }
            ],
            "wind": {
                "deg": 320,
                "speed": 1.94
            }
        },
        {
            "clouds": {
                "all": 0
            },
            "dt": 1573063200,
            "dt_txt": "2019-11-06 18:00:00",
            "main": {
                "grnd_level": 996,
                "humidity": 48,
                "pressure": 1005,
                "sea_level": 1005,
                "temp": 14.32,
                "temp_kf": 0,
                "temp_max": 14.32,
                "temp_min": 14.32
            },
            "sys": {
                "pod": "n"
            },
            "weather": [
                {
                    "description": "clear sky",
                    "icon": "01n",
                    "id": 800,
                    "main": "Clear"
                }
            ],
            "wind": {
                "deg": 309,
                "speed": 2.02
            }
        },
        {
            "clouds": {
                "all": 0
            },
            "dt": 1573074000,
            "dt_txt": "2019-11-06 21:00:00",
            "main": {
                "grnd_level": 997,
                "humidity": 40,
                "pressure": 1007,
                "sea_level": 1007,
                "temp": 18.48,
                "temp_kf": 0,
                "temp_max": 18.48,
                "temp_min": 18.48
            },
            "sys": {
                "pod": "d"
            },
            "weather": [
                {
                    "description": "clear sky",
                    "icon": "01d",
                    "id": 800,
                    "main": "Clear"
                }
            ],
            "wind": {
                "deg": 289,
                "speed": 1.83
            }
        },
        {
            "clouds": {
                "all": 0
            },
            "dt": 1573084800,
            "dt_txt": "2019-11-07 00:00:00",
            "main": {
                "grnd_level": 996,
                "humidity": 19,
                "pressure": 1006,
                "sea_level": 1006,
                "temp": 25.41,
                "temp_kf": 0,
                "temp_max": 25.41,
                "temp_min": 25.41
            },
            "sys": {
                "pod": "d"
            },
            "weather": [
                {
                    "description": "clear sky",
                    "icon": "01d",
                    "id": 800,
                    "main": "Clear"
                }
            ],
            "wind": {
                "deg": 275,
                "speed": 2.84
            }
        },
        {
            "clouds": {
                "all": 0
            },
            "dt": 1573095600,
            "dt_txt": "2019-11-07 03:00:00",
            "main": {
                "grnd_level": 995,
                "humidity": 16,
                "pressure": 1004,
                "sea_level": 1004,
                "temp": 28.53,
                "temp_kf": 0,
                "temp_max": 28.53,
                "temp_min": 28.53
            },
            "sys": {
                "pod": "d"
            },
            "weather": [
                {
                    "description": "clear sky",
                    "icon": "01d",
                    "id": 800,
                    "main": "Clear"
                }
            ],
            "wind": {
                "deg": 253,
                "speed": 5.54
            }
        },
        {
            "clouds": {
                "all": 0
            },
            "dt": 1573106400,
            "dt_txt": "2019-11-07 06:00:00",
            "main": {
                "grnd_level": 995,
                "humidity": 20,
                "pressure": 1004,
                "sea_level": 1004,
                "temp": 27.04,
                "temp_kf": 0,
                "temp_max": 27.04,
                "temp_min": 27.04
            },
            "sys": {
                "pod": "d"
            },
            "weather": [
                {
                    "description": "clear sky",
                    "icon": "01d",
                    "id": 800,
                    "main": "Clear"
                }
            ],
            "wind": {
                "deg": 254,
                "speed": 5.85
            }
        },
        {
            "clouds": {
                "all": 0
            },
            "dt": 1573117200,
            "dt_txt": "2019-11-07 09:00:00",
            "main": {
                "grnd_level": 998,
                "humidity": 34,
                "pressure": 1007,
                "sea_level": 1007,
                "temp": 20.25,
                "temp_kf": 0,
                "temp_max": 20.25,
                "temp_min": 20.25
            },
            "sys": {
                "pod": "n"
            },
            "weather": [
                {
                    "description": "clear sky",
                    "icon": "01n",
                    "id": 800,
                    "main": "Clear"
                }
            ],
            "wind": {
                "deg": 236,
                "speed": 4.49
            }
        },
        {
            "clouds": {
                "all": 9
            },
            "dt": 1573128000,
            "dt_txt": "2019-11-07 12:00:00",
            "main": {
                "grnd_level": 1000,
                "humidity": 49,
                "pressure": 1009,
                "sea_level": 1009,
                "temp": 16.2,
                "temp_kf": 0,
                "temp_max": 16.2,
                "temp_min": 16.2
            },
            "sys": {
                "pod": "n"
            },
            "weather": [
                {
                    "description": "clear sky",
                    "icon": "01n",
                    "id": 800,
                    "main": "Clear"
                }
            ],
            "wind": {
                "deg": 220,
                "speed": 2.56
            }
        },
        {
            "clouds": {
                "all": 94
            },
            "dt": 1573138800,
            "dt_txt": "2019-11-07 15:00:00",
            "main": {
                "grnd_level": 998,
                "humidity": 55,
                "pressure": 1008,
                "sea_level": 1008,
                "temp": 14.28,
                "temp_kf": 0,
                "temp_max": 14.28,
                "temp_min": 14.28
            },
            "sys": {
                "pod": "n"
            },
            "weather": [
                {
                    "description": "overcast clouds",
                    "icon": "04n",
                    "id": 804,
                    "main": "Clouds"
                }
            ],
            "wind": {
                "deg": 245,
                "speed": 1.17
            }
        }
    ],
    "message": 0
}
)";
