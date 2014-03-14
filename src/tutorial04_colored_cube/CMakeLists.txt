cmake_minimum_required(VERSION 2.8)

project(tutorial04)

add_executable(tutorial04 tutorial04.cpp)

target_link_libraries(tutorial04 common ${ALL_LIBS})
