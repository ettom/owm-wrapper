## Description:
A program to generate weather reports using the
[OpenWeatherMap](https://openweathermap.org/api) API. Reports are generated for the
current day and the following 3 days. OWM provides forecast data for free API keys
only in the format of 5 day / 3 hour forecasts. This program calculates the averages
over these reports and generates daily reports from the data. Forecasts are displayed
in accordance with the local timezone of the system. Created as a school project.

## Usage
```
Usage: ./owm-wrapper [OPTIONS]

Options:
  -h,--help                   Print this help message and exit
  -o,--output TEXT            Where to write the weather reports
                              If no output path is provided, result will be written to stdout
  -u,--unit ENUM:value in {Celsius->0,Fahrenheit->1,Kelvin->2} OR {0,1,2}
                              Temperature unit, defaults to celsius
  -l,--log                    Write API responses to owm-wrapper.log
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

- A compiler with experimental C++2a support ([clang-9+](http://llvm.org/releases/download.html), [gcc-9+](https://gcc.gnu.org/releases.html))
- [cmake 3.11+](https://cmake.org/download/)
- [git](https://git-scm.com/downloads)
- [curl](https://curl.haxx.se/)
- [libcurl](https://curl.haxx.se/libcurl/)

[pmm](https://github.com/vector-of-bool/pmm) and
[vcpkg](https://github.com/microsoft/vcpkg) are used for dependency management.

##### Installing the dependencies for Ubuntu 18.04
Get the latest version of [cmake](https://apt.kitware.com/).<br>

Install `g++-9`:

```
sudo add-apt-repository ppa:ubuntu-toolchain-r/test
sudo apt update
sudo apt install g++-9
```

Set `g++-9` as the default C++ compiler:

```
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-9 60
```

Run the following command:

```
sudo apt install git cmake curl libcurl4-gnutls-dev
```

## Building
Run the following commands:

```
git clone https://github.com/ettom/owm-wrapper.git
cd owm-wrapper
mkdir build && cd build
cmake ..
make
```

To install:
```
cmake .. -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_INSTALL_LIBDIR=/usr/lib
sudo make install
sudo ldconfig
```

To run the program with the example input file:

`make run`

To build and run the tests:

```
cmake .. -DCMAKE_BUILD_TYPE=Debug
make test
```
