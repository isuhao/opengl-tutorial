cmake_minimum_required(VERSION 2.6)
project(tutorial01)

find_package(OpenGL REQUIRED)

add_executable(tutorial01 playground.cpp)

set(ALL_LIBS ${OPENGL_LIBRARY} glfw GLEW)

target_link_libraries(tutorial01 ${ALL_LIBS})
