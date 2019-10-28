## Dependencies:
A compiler with C++17 support ([clang-5+](http://llvm.org/releases/download.html),
[gcc-7+](https://gcc.gnu.org/releases.html)), [cmake 3.6+](https://cmake.org/download/), [git](https://git-scm.com/downloads)

[conan](https://github.com/conan-io/conan) is used for dependency management.

##### Installing the dependencies for Ubuntu 18.04
Run the following commands:

```
sudo apt install git g++ cmake
pip install conan
```

## Building
Run the following commands:

```
git clone https://gitlab.cs.ttu.ee/risood/icd0004_project
cd icd0004_project
mkdir build && cd build
cmake ..
make
```

## Running
