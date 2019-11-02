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
git clone https://gitlab.cs.ttu.ee/risood/icd0004_project.git
cd icd0004_project
mkdir build && cd build
cmake ..
make
```

## Running
To run the program with the example input file:

`make run`

To run the tests:

`make run_tests`
