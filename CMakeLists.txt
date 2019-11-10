cmake_minimum_required(VERSION 3.11)
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

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

add_subdirectory(app)
add_subdirectory(core)
add_subdirectory(test)

add_custom_target(
        test
        COMMAND ${PROJECT_NAME}Test || (exit 0)
        DEPENDS ${PROJECT_NAME}Test ${PROJECT_NAME}
        WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})

add_custom_target(
        run
        COMMAND ${PROJECT_NAME} ../input.txt
        DEPENDS ${PROJECT_NAME}
        VERBATIM
        WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})
