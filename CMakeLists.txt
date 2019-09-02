cmake_minimum_required(VERSION 3.14)
project(astar)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(astar
        Agent.cpp
        Agent.h
        Cell.cpp
        Cell.h
        main.cpp)
