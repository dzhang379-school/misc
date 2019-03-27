cmake_minimum_required(VERSION 3.8)
project(hw02)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(SOURCE_FILES picosha2.h date-test.cpp)

add_executable(hw02 ${SOURCE_FILES})