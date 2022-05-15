cmake_minimum_required(VERSION 3.10)
project(banking)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
option(BUILD_TESTS "Build tests" OFF)
add_library(account STATIC banking/Account.cpp)
target_include_directories(account PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/banking)

add_library(transaction STATIC banking/Transaction.cpp)
target_include_directories(transaction
 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/banking)
if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/third-party/gtest)
  file(GLOB ${PROJECT_NAME}_TEST_SOURCES tests/*.cpp)
  add_executable(check ${${PROJECT_NAME}_TEST_SOURCES})
  target_compile_options(check PRIVATE --coverage)
  target_link_libraries(check PRIVATE account transaction gtest_main gmock_main  --coverage)
  add_test(NAME check COMMAND check)
endif()

option(BUILD_EXAMPLES "Build examples" OFF)

project(print)

add_library(print STATIC ${CMAKE_CURRENT_SOURCE_DIR}/sources/print.cpp)

target_include_directories(print PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

if(BUILD_EXAMPLES)
  file(GLOB EXAMPLE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/examples/*.cpp")
  foreach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
    get_filename_component(EXAMPLE_NAME ${EXAMPLE_SOURCE} NAME_WE)
    add_executable(${EXAMPLE_NAME} ${EXAMPLE_SOURCE})
    target_link_libraries(${EXAMPLE_NAME} print)
    install(TARGETS ${EXAMPLE_NAME}
      RUNTIME DESTINATION bin
    )
  endforeach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
endif()

install(TARGETS print
    EXPORT print-config
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION include)
install(EXPORT print-config DESTINATION cmake)

include(CPackConfig.cmake)







