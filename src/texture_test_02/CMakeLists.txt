cmake_minimum_required(VERSION 2.8)

project(texture_test_02)

add_executable(texture_test_02 main.cpp)

target_link_libraries(texture_test_02 common ${ALL_LIBS})
