file(GLOB_RECURSE SRC_LIST *.cpp *.h)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_definitions("-std=c++2a")

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}Core ${CONAN_LIBS})

include(FetchContent)
FetchContent_Declare(
    cli11 GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git)
FetchContent_MakeAvailable(cli11)

target_link_libraries(${PROJECT_NAME} CLI11::CLI11)

target_compile_options(
    ${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Wconversion
    -Wsign-conversion -Wshadow)

install(TARGETS ${PROJECT_NAME})
