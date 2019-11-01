set(SUBPROJECT_NAME ${PROJECT_NAME}Core)
file(GLOB_RECURSE SRC_LIST *.cpp *.h)
add_library(${SUBPROJECT_NAME} ${SRC_LIST})

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
add_definitions("-std=c++17")

target_include_directories(${SUBPROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
                                                     ${CONAN_LIBS})

target_link_libraries(${SUBPROJECT_NAME} restclient-cpp)

target_compile_options(
        ${SUBPROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Wconversion
                                   -Wsign-conversion -Wshadow)
