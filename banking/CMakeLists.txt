project(banking_lib)

cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDART 11)
set(CMAKE_CXX_STANDART_REQUIRED ON)

option(BUILD_TESTS "Build tests" OFF)

option(COVERAGE ON)

if (NOT TARGET libbanking)
    add_library(libbanking STATIC
        ${CMAKE_CURRENT_LIST_DIR}/Account.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Transaction.cpp
    )

    install(TARGETS libbanking
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
    )
endif(NOT TARGET libbanking)
