cmake_minimum_required(VERSION 2.8)

project(tutorial05)

add_executable(tutorial05 tutorial03.cpp)

target_link_libraries(tutorial05 common ${ALL_LIBS})
