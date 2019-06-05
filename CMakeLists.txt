cmake_minimum_required (VERSION 3.8)

project(maze-movement-lib)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

find_package(Boost 1.68.0 REQUIRED COMPONENTS program_options)

include_directories(inc ${Boost_INCLUDE_DIRS})

add_library(maze-movement SHARED src/maze_movement.cpp)

add_executable(demo src/demo.cpp)

target_link_libraries(demo maze-movement Boost::program_options)

add_executable(lib_test test/maze_movement_lib_test.cpp)

target_include_directories(lib_test ${GTEST_INCLUDE_DIRS})

target_link_libraries(lib_test maze-movement ${GTEST_LIBRARIES} pthread)