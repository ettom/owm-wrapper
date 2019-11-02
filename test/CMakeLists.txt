set(SUBPRROJECT_NAME ${PROJECT_NAME}Test)
file(GLOB_RECURSE SRC_LIST *)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_definitions("-std=c++17")

add_executable(${SUBPRROJECT_NAME} ${SRC_LIST})
target_link_libraries(${SUBPRROJECT_NAME} ${PROJECT_NAME}Core ${CONAN_LIBS})
target_compile_options(
	${PROJECT_NAME}Test PRIVATE -Wall)
