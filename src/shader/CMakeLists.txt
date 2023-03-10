cmake_minimum_required(VERSION 3.24)
project(SHD)

add_library(SHD STATIC
        Shader.cpp
        Shader.h)

find_package(OpenGL REQUIRED)

target_link_libraries(SHD
        ${CMAKE_SOURCE_DIR}/../../lib/libglfw3.a
        ${CMAKE_SOURCE_DIR}/../../lib/glew32s.lib
        ${OPENGL_LIBRARY})