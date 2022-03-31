cmake_minimum_required(VERSION 3.0)
project(calculator_test)

set(CMAKE_CXX_STANDARD 11)

include_directories(${gtest_SOURCE_DIR}/include)

add_executable(calculator_test calculator_test.cpp)
target_link_libraries(calculator_test gtest gtest_main)
