cmake_minimum_required(VERSION 2.8)

project(tutorial02)

add_executable(tutorial02 tutorial02.cpp)

target_link_libraries(tutorial02 common ${ALL_LIBS})
