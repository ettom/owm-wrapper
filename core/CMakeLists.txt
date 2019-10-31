set(SUBPROJECT_NAME ${PROJECT_NAME}Core)
file(GLOB_RECURSE SRC_LIST *.cpp *.h)
add_library(${SUBPROJECT_NAME} ${SRC_LIST})

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
add_definitions("-std=c++17")

target_include_directories(${SUBPROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
	${CONAN_LIBS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
