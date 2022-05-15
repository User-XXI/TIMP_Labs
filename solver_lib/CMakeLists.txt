cmake_minimum_required(VERSION 3.12) 
project(solver_lib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(solver_lib STATIC ${CMAKE_CURRENT_SOURCE_DIR}/solver.cpp)

add_library(solver ${CMAKE_CURRENT_SOURCE_DIR}/solver.cpp)

