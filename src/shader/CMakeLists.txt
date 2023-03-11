cmake_minimum_required(VERSION 3.24)
project(S3DESHD)

add_library(S3DESHD STATIC
        S3DEshader.cpp
        S3DEshader.h)

find_package(OpenGL REQUIRED)

target_link_libraries(S3DESHD
        ${CMAKE_SOURCE_DIR}/../../lib/glew32s.lib
        ${OPENGL_LIBRARY})