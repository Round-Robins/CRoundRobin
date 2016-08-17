cmake_minimum_required(VERSION 3.6)
project(CRoundRobin)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c11")

set(SOURCE_FILES src/round_robin.c)
add_library(CRoundRobin ${SOURCE_FILES})