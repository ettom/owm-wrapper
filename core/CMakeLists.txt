set(SUBPROJECT_NAME ${PROJECT_NAME}Core)
file(GLOB_RECURSE SRC_LIST *.cpp *.h)
add_library(${SUBPROJECT_NAME} ${SRC_LIST})

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
add_definitions("-std=c++17")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

include(FetchContent)
FetchContent_Declare(
    restclient-cpp GIT_REPOSITORY https://github.com/mrtazz/restclient-cpp.git)

FetchContent_MakeAvailable(restclient-cpp)

target_link_libraries(${SUBPROJECT_NAME} restclient-cpp)

target_include_directories(${SUBPROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    ${CONAN_LIBS} ${restclient-cpp_SOURCE_DIR}/include ${restclient-cpp_BINARY_DIR}/include)

target_compile_options(
    ${SUBPROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Wconversion
    -Wsign-conversion -Wshadow)
