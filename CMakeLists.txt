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

# gtest isnt needed when build type is release
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(debug_libs "gtest")
    set(pmm_debug "DEBUG")
endif()

include(pmm.cmake)
pmm(
    VCPKG
    REVISION 7a14422290e7583c68ee290f7dbb5d61872a7a99
    REQUIRES nlohmann-json ${debug_libs}
    ${pmm_debug}
    )

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -ggdb \
    -fno-limit-debug-info -fsanitize=undefined \
    -fsanitize=implicit-conversion -fsanitize=integer \
    -fno-limit-debug-info")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
endif()

add_subdirectory(core)
add_subdirectory(app)

add_custom_target(
    run
    COMMAND ${PROJECT_NAME} -i ../input.txt
    DEPENDS ${PROJECT_NAME}
    VERBATIM
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_subdirectory(test)
    add_custom_target(
        test
        COMMAND ${PROJECT_NAME}Test || (exit 0)
        DEPENDS ${PROJECT_NAME}Test ${PROJECT_NAME}
        WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})
endif()

