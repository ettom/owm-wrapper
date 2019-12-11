set(SUBPROJECT_NAME ${PROJECT_NAME}Test)
file(GLOB_RECURSE SRC_LIST *.cpp *.h)

add_definitions("-std=c++2a")

add_executable(${SUBPROJECT_NAME} ${SRC_LIST})
target_link_libraries(${SUBPROJECT_NAME} PRIVATE ${PROJECT_NAME}Core
    ${CONAN_LIBS})

target_compile_options(
    ${SUBPROJECT_NAME}
    PRIVATE -Wall -Wextra -pedantic -Wconversion
    -Wsign-conversion -Wshadow
    # designated initializers should be supported in c++2a
    -Wno-missing-field-initializers
    $<$<CXX_COMPILER_ID:Clang>:
    -Wno-c99-extensions>)
