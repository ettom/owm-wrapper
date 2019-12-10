cmake_minimum_required(VERSION 3.11)
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

set(default_build_type "Release")

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(
        STATUS
            "Setting build type to '${default_build_type}' as none was specified."
    )
    set(CMAKE_BUILD_TYPE
        "${default_build_type}"
        CACHE STRING "Choose the type of build." FORCE)
    # Set the possible values of build type for cmake-gui
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release")
endif()

# Download automatically, you can also just copy the conan.cmake file
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

conan_cmake_run(
    CONANFILE conanfile.txt
    BUILD_TYPE "None"
    BASIC_SETUP CMAKE_TARGETS
    BUILD missing
    SETTINGS compiler.libcxx=libstdc++11)

add_subdirectory(core)
add_subdirectory(app)
add_subdirectory(test)

add_custom_target(
    test
    COMMAND ${PROJECT_NAME}Test || (exit 0)
    DEPENDS ${PROJECT_NAME}Test ${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})

add_custom_target(
    run
    COMMAND ${PROJECT_NAME} -i ../input.txt -o output.json
    DEPENDS ${PROJECT_NAME}
    VERBATIM
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})
