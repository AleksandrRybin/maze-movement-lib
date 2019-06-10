find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(maze_movement_test maze_movement_test.cpp)

target_link_libraries(maze_movement_test maze_movement ${GTEST_LIBRARIES} pthread)

add_executable(point_test point_test.cpp)

target_link_libraries(point_test maze_movement ${GTEST_LIBRARIES} pthread)

gtest_discover_tests(maze_movement_test)

gtest_discover_tests(point_test)
