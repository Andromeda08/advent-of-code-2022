cmake_minimum_required(VERSION 3.23)
project(AdventOfCode)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} src/main.cpp
        src/Day2.hpp src/Day1.hpp src/Day3.hpp)

target_include_directories(${PROJECT_NAME} PUBLIC inc)
