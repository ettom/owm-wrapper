cmake_minimum_required(VERSION 3.11)
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

# build type handling
set(default_build_type "Release")
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(
        STATUS
        "Setting build type to '${default_build_type}' as none was specified."
        )
    set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
        STRING "Choose the type of build." FORCE)
endif()


if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -ggdb \
    -fno-limit-debug-info -fsanitize=undefined \
    -fsanitize=implicit-conversion -fsanitize=integer \
    -fno-limit-debug-info")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
endif()

# initialize conan
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(
        STATUS
        "Downloading conan.cmake from https://github.com/conan-io/cmake-conan"
        )
    file(
        DOWNLOAD
        "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
        "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

# treat conan includes as system libraries to silence compiler warnings for them
set(CONAN_SYSTEM_INCLUDES ON)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    conan_cmake_run(
        BUILD_TYPE "Debug"
        REQUIRES
        gtest/1.8.1@bincrafters/stable
        jsonformoderncpp/3.7.0@vthiery/stable
        BASIC_SETUP CMAKE_TARGETS
        BUILD missing
        SETTINGS compiler.libcxx=libstdc++11)

    add_subdirectory(test)
    add_custom_target(
        test
        COMMAND ${PROJECT_NAME}Test || (exit 0)
        DEPENDS ${PROJECT_NAME}Test ${PROJECT_NAME}
        WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})
endif()

# no need to build gtest for release
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    conan_cmake_run(
        BUILD_TYPE "Release"
        REQUIRES
        jsonformoderncpp/3.7.0@vthiery/stable
        BASIC_SETUP CMAKE_TARGETS
        BUILD missing
        SETTINGS compiler.libcxx=libstdc++11)
endif()

add_subdirectory(core)
add_subdirectory(app)

add_custom_target(
    run
    COMMAND ${PROJECT_NAME} -i ../input.txt
    DEPENDS ${PROJECT_NAME}
    VERBATIM
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})
