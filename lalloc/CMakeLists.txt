cmake_minimum_required(VERSION 3.17)
project(lalloc)

set(CMAKE_CXX_STANDARD 20)

add_executable(lalloc main.cpp LASAalloc.h LASAalloc.cpp)