cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

project(task1
        VERSION 1.0
        DESCRIPTION "1st task from the Yandex contest. Internship Autumn-winter 2022: backend"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wpedantic -Wextra -lm -O2 -fno-stack-limit -std=c++1z")

add_executable(task1 task1/main.cpp)
add_executable(task2 task2/main.cpp)
