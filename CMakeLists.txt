cmake_minimum_required(VERSION 3.24)
project(S3DE)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")

add_executable(S3DE
        src/main.cpp)

add_subdirectory(src/shader)

find_package(OpenGL REQUIRED)

target_link_libraries(S3DE
        ${CMAKE_BINARY_DIR}/src/shader/libSHD.a
        ${CMAKE_SOURCE_DIR}/lib/libglfw3.a
        ${CMAKE_SOURCE_DIR}/lib/glew32s.lib
        ${OPENGL_LIBRARY})