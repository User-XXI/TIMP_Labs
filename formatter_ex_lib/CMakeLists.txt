cmake_minimum_required(VERSION 3.4)
project(formatter_ex)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories("../formatter_lib")

add_library(formatter_exlib STATIC ${CMAKE_CURRENT_SOURCE_DIR}/formatter_ex.cpp)

add_executable(formatter_ex ${CMAKE_CURRENT_SOURCE_DIR}/formatter_ex.cpp)

target_link_libraries(formatter_ex formatter_exlib)
