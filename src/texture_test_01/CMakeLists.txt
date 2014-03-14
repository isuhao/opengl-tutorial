cmake_minimum_required(VERSION 2.8)

project(texture_test_01)

add_executable(texture_test_01 main.cpp)

target_link_libraries(texture_test_01 common ${ALL_LIBS})
