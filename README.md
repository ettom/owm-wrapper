## Description:
A program to generate weather reports using the
[OpenWeatherMap](https://openweathermap.org/api) API. Reports are generated for the
current day and the following 3 days. OWM provides forecast data for free API keys
only in the format of 5 day / 3 hour forecasts. This program calculates the averages
over these reports and generates daily reports from the data. Created as a school
project.

## Usage
```
Usage: ./owm-wrapper [OPTIONS]

Options:
  -h,--help                   Print this help message and exit
  -o,--output TEXT            Where to write the weather reports
                              If no output path is provided, result will be written to stdout
  -u,--unit ENUM:value in {Celsius->0,Fahrenheit->1,Kelvin->2} OR {0,1,2}
                              Temperature unit, defaults to celsius
[Option Group: input]
  Cities to generate reports for
  [Exactly 1 of the following options is required]
  Options:
    -i,--input TEXT:FILE        Path to a file containing the city names for which reports are to be generated
                                Each city name must be on a separate line
    -c,--city TEXT ...          List of city names

```

For example: to generate reports for London in fahrenheit and store the result in
`output.json`, you could do `owm-wrapper -c London -u fahrenheit -o output.json`.


## Dependencies:

- A compiler with C++17 support ([clang-5+](http://llvm.org/releases/download.html), [gcc-8+](https://gcc.gnu.org/releases.html))
- [cmake 3.11+](https://cmake.org/download/)
- [git](https://git-scm.com/downloads)
- [python3](https://www.python.org/downloads/)
- [pip3](https://pypi.org/project/pip/)
- [libcurl](https://curl.haxx.se/libcurl/)

[conan](https://github.com/conan-io/conan) is used for dependency management.

##### Installing the dependencies for Ubuntu 18.04
Get the latest version of [cmake](https://apt.kitware.com/).<br>
Run the following commands:

```
sudo apt install git g++-8 cmake python3-pip libcurl4-gnutls-dev
sudo pip3 install conan
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-8 60
```

## Building
Run the following commands:

```
git clone https://github.com/ettom/owm-wrapper.git
cd owm-wrapper
mkdir build && cd build
cmake ..
make
sudo make install
```

To run the program with the example input file:

`make run`

To run the tests:

`make test`
