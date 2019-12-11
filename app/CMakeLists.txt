file(GLOB_RECURSE SRC_LIST *.cpp *.h)

add_definitions("-std=c++2a")

add_executable(${PROJECT_NAME} ${SRC_LIST})

target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}Core)

find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} nlohmann_json nlohmann_json::nlohmann_json)

target_compile_options(
    ${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Wconversion
                            -Wsign-conversion -Wshadow)

install(TARGETS ${PROJECT_NAME})
