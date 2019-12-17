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

include(cmake/pmm.cmake)
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
    -fno-limit-debug-info -fprofile-arcs -ftest-coverage")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -fprofile-arcs -ftest-coverage")
endif()


if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    # test coverage
    set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
    include(CodeCoverage)
    SETUP_TARGET_FOR_COVERAGE_LCOV(
        NAME ${PROJECT_NAME}_coverage
        EXECUTABLE ${PROJECT_NAME}Test
        DEPENDENCIES ${PROJECT_NAME}Test
        LCOV_ARGS --base-directory ${PROJECT_SOURCE_DIR} --no-external
        --exclude "${PROJECT_SOURCE_DIR}/test/\\*"
        --exclude "${PROJECT_SOURCE_DIR}/build/\\*"
        --exclude "${PROJECT_SOURCE_DIR}/app/\\*"
        )

    add_subdirectory(test)
    add_custom_target(
        test
        COMMAND ${PROJECT_NAME}Test || :
        DEPENDS ${PROJECT_NAME}Core
        WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})

    add_custom_target(
        test_xml
        COMMAND ${PROJECT_NAME}Test --gtest_output=xml:gtestresults.xml || :
        DEPENDS ${PROJECT_NAME}Core
        WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})

    add_custom_target(
        clean_gcda
        COMMAND find ${CMAKE_PROJECT_DIR} -name '*.gcda' | xargs rm 2>/dev/null || :
        COMMENT "Cleaning old .gcda files")

endif()

add_subdirectory(core)
add_subdirectory(app)

add_custom_target(
    run
    COMMAND ${PROJECT_NAME} -i ../input.txt
    DEPENDS ${PROJECT_NAME}
    VERBATIM
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})
