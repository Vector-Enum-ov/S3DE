cmake_minimum_required(VERSION 3.24)
project(S3DE)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")

add_executable(S3DE
        src/main.cpp)

target_include_directories(S3DE PUBLIC include/)
target_link_directories(S3DE PUBLIC lib/)

find_package(OpenGL REQUIRED)
if (NOT_OPENGL)
    MESSAGE("OPENGL NOT FOUND")
    RETURN()
else()
    include_directories(${OPENGL_INCLUDE_DIRECTORY})
endif()

target_link_libraries(S3DE
        glfw3
        glew32s
        ${OPENGL_LIBRARY})
