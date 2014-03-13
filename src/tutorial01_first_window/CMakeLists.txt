cmake_minimum_required(VERSION 2.8)

project(tutorial01)

add_executable(tutorial01 tutorial01.cpp)

target_link_libraries(tutorial01 ${ALL_LIBS})
