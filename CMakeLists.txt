# CMake file for opengl tutorial
#

cmake_minimum_required(VERSION 2.8)

project (opengl_tutorial)

find_package(OpenGL REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/extern)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(GLFW_LIB glfw)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    set(GLFW_LIB glfw3)
else()
    set(GLFW_LIB glfw)
endif()

set(ALL_LIBS ${OPENGL_LIBRARY} ${GLFW_LIB} GLEW)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_subdirectory(src/tutorial01_first_window)

