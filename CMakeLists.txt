# CMake file for opengl tutorial
#

cmake_minimum_required(VERSION 2.8)

project (opengl_tutorial)

find_package(OpenGL REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/extern)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    add_definitions(-D__UNIX__)
    add_definitions(-D__LINUX__)
    set(GLFW_LIB glfw)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    add_definitions(-D__UNIX__)
    add_definitions(-D__APPLE__)
    set(GLFW_LIB glfw3)
    FIND_PATH(GL_H_INCLUDE_DIR gl.h)
    include_directories(${GL_H_INCLUDE_DIR})
else()
    set(GLFW_LIB glfw)
endif()

set(ALL_LIBS ${OPENGL_LIBRARY} ${GLFW_LIB} GLEW)

# GLM setting
add_definitions(-DGLM_FORCE_RADIANS)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_subdirectory(src)

