cmake_minimum_required(VERSION 3.17)
project(towers_of_hanoi)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(towers_of_hanoi
        disc.h
        main.cpp
        stack.cpp
        stack.h)
