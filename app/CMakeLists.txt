file(GLOB_RECURSE SRC_LIST *.cpp *.h)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_definitions("-std=c++17")

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}Core ${CONAN_LIBS})


target_compile_options(
        ${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Wconversion
                                -Wsign-conversion -Wshadow)
