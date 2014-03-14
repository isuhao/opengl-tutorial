cmake_minimum_required(VERSION 2.8)

project(tutorial03)

add_executable(tutorial03 tutorial03.cpp)

target_link_libraries(tutorial03 common ${ALL_LIBS})
