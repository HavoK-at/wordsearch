cmake_minimum_required(VERSION 3.6)
project(havok_wordsearch)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3")

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(havok_wordsearch ${SOURCE_FILES})