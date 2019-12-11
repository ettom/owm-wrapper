set(SUBPROJECT_NAME ${PROJECT_NAME}Core)
file(GLOB_RECURSE SRC_LIST *.cpp *.h)
add_library(${SUBPROJECT_NAME} ${SRC_LIST})

add_definitions("-std=c++2a")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

include(FetchContent)
FetchContent_Declare(
    restclient-cpp GIT_REPOSITORY https://github.com/mrtazz/restclient-cpp.git)

FetchContent_GetProperties(restclient-cpp)
if(NOT restclient-cpp_POPULATED)
    FetchContent_Populate(restclient-cpp)
    set(jsoncpp_FOUND OFF CACHE BOOL "" FORCE)
    add_subdirectory(${restclient-cpp_SOURCE_DIR} ${restclient-cpp_BINARY_DIR})
endif()

target_link_libraries(${SUBPROJECT_NAME} restclient-cpp)
target_include_directories(
    ${SUBPROJECT_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CONAN_LIBS}
    ${restclient-cpp_SOURCE_DIR}/include
    ${restclient-cpp_BINARY_DIR}/include)

target_compile_options(
    ${SUBPROJECT_NAME}
    PRIVATE -Wall -Wextra -pedantic -Wconversion
    -Wsign-conversion -Wshadow)
