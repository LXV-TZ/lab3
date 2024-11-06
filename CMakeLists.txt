cmake_minimum_required(VERSION 3.29)
project(lab3_code)

set(CMAKE_CXX_STANDARD 14)

include_directories(task1)

add_executable(lab3_code
    task1/application.h
    task1/backtrack.cpp
    task1/backtrack.h
    task1/main.cpp
        task1/application.cpp
        task1/position.h
        task1/position.cpp)
