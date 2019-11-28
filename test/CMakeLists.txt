set(SUBPROJECT_NAME ${PROJECT_NAME}Test)
file(GLOB_RECURSE SRC_LIST *.cpp *.h)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_definitions("-std=c++2a")

add_executable(${SUBPROJECT_NAME} ${SRC_LIST})
target_link_libraries(${SUBPROJECT_NAME} PRIVATE ${PROJECT_NAME}Core
                                                 ${CONAN_LIBS})

target_compile_options(${PROJECT_NAME}Test PRIVATE -Wall)
