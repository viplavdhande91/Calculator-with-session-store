cmake_minimum_required(VERSION 3.0)
project(using_googletest)

include(FetchContent)

option(BUILD_GMOCK "" OFF)
option(INSTALL_GTEST "" OFF)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.10.0
)

FetchContent_MakeAvailable(googletest)

add_subdirectory(calculator_test)
