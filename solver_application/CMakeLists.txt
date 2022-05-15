cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(CPACK_GENERATOR_DEB OFF)

project(solver)


add_executable(solver equation.cpp)

include_directories(../formatter_ex_lib ../solver_lib)

add_subdirectory(../formatter_ex_lib formatter_ex)
add_subdirectory(../solver_lib solver_lib)

target_link_libraries(solver formatter_ex solver_lib)

install(TARGETS solver RUNTIME DESTINATION bin)
set(CPACK_SOURCE_GENERATOR "TGZ;ZIP")

if(CPACK_GENERATOR_DEB)
    set(CPACK_DEBIAN_PACKAGE_MAINTAINER "name")
	set(CPACK_GENERATOR "DEB")
endif()

if(CPACK_GENERATOR_DMG)
	set(MACOSX_BUNDLE TRUE)
	set(CPACK_GENERATOR "DragNDrop")
endif()

include(CPack)
unset(CPACK_GENERATOR_DEB CACHE)
