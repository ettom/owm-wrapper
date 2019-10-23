cmake_minimum_required(VERSION 3.8)
include(ExternalProject)

ExternalProject_Add(
        json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.6.1
        GIT_SHALLOW true
        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}
                   -DJSON_MultipleHeaders=ON -DBUILD_TESTING=OFF)

add_custom_target(dependencies DEPENDS json)
