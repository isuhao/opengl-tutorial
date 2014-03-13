# CMake file for opengl tutorial
#

cmake_minimum_required(VERSION 2.8)

project (common)

file(GLOB common_SRC "*.c")

add_library(common ${common_SRC})

target_link_libraries(common ${ALL_LIBS})

