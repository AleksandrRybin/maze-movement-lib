#include <string>
#include <list>
#include <iostream>
#include <fstream>

#include <gtest/gtest.h>

#include <maze_movement.hpp>
#include <point.hpp>

TEST(ConstructorTests, CreateEmptyMazeTest) {
    IntegerMaze2D maze;

    EXPECT_TRUE(maze.is_empty());
    EXPECT_EQ(maze.size(), 0);
}

TEST(ConstructorTests, CreateFromFileTest) {
    std::ofstream test_file("test_board.txt", std::ios_base::out);

    if (!test_file.is_open()) {
        FAIL();
    }
    
    std::list<IntegerPoint2D> points = {
        {0, 0}, {1, 2}, {-2, -2}, {-3, -5}
    };

    for (const auto& point : points) {
        test_file << point << ",";
    }
    
    test_file.close();

    IntegerMaze2D maze("test_board.txt");

    EXPECT_FALSE(maze.is_empty());
    EXPECT_EQ(maze.size(), 4);

    EXPECT_TRUE(maze.have_point({0, 0}));
    EXPECT_TRUE(maze.have_point({1, 2}));
    EXPECT_TRUE(maze.have_point({-2, -2}));
    EXPECT_TRUE(maze.have_point({-3, -5}));

    std::remove("test_board.txt");
}

TEST(ConstructorTests, CreateFromIncorrectFileTest) {
    std::ofstream test_file("test_board.txt", std::ios_base::out);

    if (!test_file.is_open()) {
        FAIL();
    }

    test_file << "(1; 0), (-1, -1}, {0, 0}, [-2, -2];";

    test_file.close();

    IntegerMaze2D maze("test_board.txt");

    EXPECT_TRUE(maze.is_empty());
    EXPECT_EQ(maze.size(), 0);

    EXPECT_FALSE(maze.have_point({1, 0}));
    EXPECT_FALSE(maze.have_point({-1, -1}));
    EXPECT_FALSE(maze.have_point({0, 0}));
    EXPECT_FALSE(maze.have_point({-2, -2}));

    std::remove("test_board.txt");
}

TEST(ConstructorTests, CreateFromNoExistFileTest) {
    IntegerMaze2D maze("test_board.txt");

    EXPECT_TRUE(maze.is_empty());
    EXPECT_EQ(maze.size(), 0);
}

TEST(ConstructorTests, CreateFromList) {
    std::list<IntegerPoint2D> points = {
        {0, 0}, {1, 2}, {-2, -2}, {-3, -5}
    };

    IntegerMaze2D maze(points);

    EXPECT_FALSE(maze.is_empty());
    EXPECT_EQ(maze.size(), 4);

    EXPECT_TRUE(maze.have_point({0, 0}));
    EXPECT_TRUE(maze.have_point({1, 2}));
    EXPECT_TRUE(maze.have_point({-2, -2}));
    EXPECT_TRUE(maze.have_point({-3, -5}));
}

TEST(ConstructorTests, CreateFromEmptyList) {
    std::list<IntegerPoint2D> points;

    IntegerMaze2D maze(points);

    EXPECT_TRUE(maze.is_empty());
    EXPECT_EQ(maze.size(), 0);
}

TEST(EditMazeTests, AddNoExistPoints) {
    IntegerMaze2D maze;

    bool add_result = maze.add_point({0, 0});

    EXPECT_FALSE(maze.is_empty());
    EXPECT_EQ(maze.size(), 1);
    EXPECT_TRUE(add_result);

    EXPECT_TRUE(maze.have_point({0, 0}));

    add_result = maze.add_point({1, 1});

    EXPECT_FALSE(maze.is_empty());
    EXPECT_EQ(maze.size(), 2);
    EXPECT_TRUE(add_result);

    EXPECT_TRUE(maze.have_point({0, 0}));
    EXPECT_TRUE(maze.have_point({1, 1}));
}

TEST(EditMazeTests, AddExistPoints) {
    std::list<IntegerPoint2D> points = {
        {0, 0}, {1, 2}, {-2, -2}, {-3, -5}
    };

    IntegerMaze2D maze(points);

    std::size_t prev_size = maze.size();
    bool add_result = maze.add_point({0, 0});

    EXPECT_EQ(maze.size(), prev_size);
    EXPECT_FALSE(add_result);

    add_result = maze.add_point({1, 2});

    EXPECT_EQ(maze.size(), prev_size);
    EXPECT_FALSE(add_result);
}

TEST(EditMazeTests, RemoveNoExistPoints) {
    std::list<IntegerPoint2D> points = {
        {0, 0}, {1, 2}, {-2, -2}, {-3, -5}
    };

    IntegerMaze2D maze(points);

    std::size_t prev_size = maze.size();
    bool remove_result = maze.remove_point({5, 5});

    EXPECT_EQ(maze.size(), prev_size);
    EXPECT_FALSE(remove_result);
}

TEST(EditMazeTests, RemoveExistPoints) {
    std::list<IntegerPoint2D> points = {
        {0, 0}, {1, 2}, {-2, -2}, {-3, -5}
    };

    IntegerMaze2D maze(points);

    std::size_t prev_size = maze.size();
    bool remove_result = maze.remove_point({0, 0});

    EXPECT_EQ(maze.size(), prev_size - 1);
    EXPECT_TRUE(remove_result);
}

TEST(NavigationTests, HaveNeighbourTest) {
    std::list<IntegerPoint2D> points = {
        {0, 0}, {1, 2}, {-2, -2}, {-3, -5}
    };

    IntegerMaze2D maze(points);

    bool have_neighbour = maze.have_neighbour({0, -1}, IntegerMaze2D::MOVEMENT::UP);
    EXPECT_TRUE(have_neighbour);

    have_neighbour = maze.have_neighbour({1, 3}, IntegerMaze2D::MOVEMENT::DOWN);
    EXPECT_TRUE(have_neighbour);

    have_neighbour = maze.have_neighbour({-1, -2}, IntegerMaze2D::MOVEMENT::LEFT);
    EXPECT_TRUE(have_neighbour);

    have_neighbour = maze.have_neighbour({-4, -5}, IntegerMaze2D::MOVEMENT::RIGHT);
    EXPECT_TRUE(have_neighbour);
}

TEST(NavigationTests, NoHaveNeighbourTest) {
    std::list<IntegerPoint2D> points = {
        {0, 0}, {1, 2}, {-2, -2}, {-3, -5}
    };

    IntegerMaze2D maze(points);

    bool have_neighbour = maze.have_neighbour({0, 0}, IntegerMaze2D::MOVEMENT::UP);
    EXPECT_FALSE(have_neighbour);

    have_neighbour = maze.have_neighbour({-1, -5}, IntegerMaze2D::MOVEMENT::DOWN);
    EXPECT_FALSE(have_neighbour);

    have_neighbour = maze.have_neighbour({10, 10}, IntegerMaze2D::MOVEMENT::LEFT);
    EXPECT_FALSE(have_neighbour);

    have_neighbour = maze.have_neighbour({-3, -5}, IntegerMaze2D::MOVEMENT::RIGHT);
    EXPECT_FALSE(have_neighbour);
}

TEST(NavigationTests, StepToExistPointTest) {
    std::list<IntegerPoint2D> points = {
        {0, 0}, {1, 2}, {-2, -2}, {-3, -5}
    };

    IntegerMaze2D maze(points);

    IntegerPoint2D step_result = maze.navigate({0, -1}, IntegerMaze2D::MOVEMENT::UP);
    EXPECT_EQ(step_result, IntegerPoint2D(0, 0));

    step_result = maze.navigate({1, 3}, IntegerMaze2D::MOVEMENT::DOWN);
    EXPECT_EQ(step_result, IntegerPoint2D(1, 2));

    step_result = maze.navigate({-1, -2}, IntegerMaze2D::MOVEMENT::LEFT);
    EXPECT_EQ(step_result, IntegerPoint2D(-2, -2));

    step_result = maze.navigate({-4, -5}, IntegerMaze2D::MOVEMENT::RIGHT);
    EXPECT_EQ(step_result, IntegerPoint2D(-3, -5));
}

TEST(NavigationTests, StepToNoExistPointTest) {
    std::list<IntegerPoint2D> points = {
        {0, 0}, {1, 2}, {-2, -2}, {-3, -5}
    };

    IntegerMaze2D maze(points);

    IntegerPoint2D step_result = maze.navigate({0, 0}, IntegerMaze2D::MOVEMENT::UP);
    EXPECT_EQ(step_result, IntegerPoint2D(0, 0));

    step_result = maze.navigate({-1, -5}, IntegerMaze2D::MOVEMENT::DOWN);
    EXPECT_EQ(step_result, IntegerPoint2D(-1, -5));

    step_result = maze.navigate({10, 10}, IntegerMaze2D::MOVEMENT::LEFT);
    EXPECT_EQ(step_result, IntegerPoint2D(10, 10));

    step_result = maze.navigate({-3, -5}, IntegerMaze2D::MOVEMENT::RIGHT);
    EXPECT_EQ(step_result, IntegerPoint2D(-3, -5));
}

TEST(NavigationTests, RouteNavigation1) {
    std::list<IntegerPoint2D> points = {
        {0, 0}, {1, 0}, {2, 0},
        {0, 1}, {1, 1}, {2, 1},
        {0, 2}, {1, 2}, {2, 2}
    };

    IntegerPoint2D start_point = {0, 0};

    std::list<IntegerMaze2D::MOVEMENT> movements = {
        IntegerMaze2D::MOVEMENT::UP,
        IntegerMaze2D::MOVEMENT::UP,
        IntegerMaze2D::MOVEMENT::RIGHT,
        IntegerMaze2D::MOVEMENT::RIGHT,
        IntegerMaze2D::MOVEMENT::DOWN,
        IntegerMaze2D::MOVEMENT::LEFT,
        IntegerMaze2D::MOVEMENT::LEFT,
        IntegerMaze2D::MOVEMENT::DOWN
    };

    IntegerMaze2D maze(points);

    IntegerPoint2D result = maze.navigate(start_point, movements);

    EXPECT_EQ(result, IntegerPoint2D(0, 0));
}

TEST(NavigationTests, RouteNavigation2) {
    std::list<IntegerPoint2D> points = {
        {0, 0}, {1, 0}, {2, 0},
        {0, 1}, {1, 1}, {2, 1},
        {0, 2}, {1, 2}, {2, 2}
    };

    IntegerPoint2D start_point = {1, 1};

    std::list<IntegerMaze2D::MOVEMENT> movements = {
        IntegerMaze2D::MOVEMENT::UP,
        IntegerMaze2D::MOVEMENT::UP,
        IntegerMaze2D::MOVEMENT::RIGHT,
        IntegerMaze2D::MOVEMENT::RIGHT,
        IntegerMaze2D::MOVEMENT::DOWN,
        IntegerMaze2D::MOVEMENT::DOWN,
        IntegerMaze2D::MOVEMENT::DOWN,
        IntegerMaze2D::MOVEMENT::DOWN,
        IntegerMaze2D::MOVEMENT::DOWN,
        IntegerMaze2D::MOVEMENT::LEFT,
        IntegerMaze2D::MOVEMENT::LEFT
    };

    IntegerMaze2D maze(points);

    IntegerPoint2D result = maze.navigate(start_point, movements);

    EXPECT_EQ(result, IntegerPoint2D(0, 0));
}

TEST(NavigationTests, RouteNavigation3) {
    std::list<IntegerPoint2D> points = {
        {0, 0}, {1, 0}, {2, 0},
        {0, 1}, {1, 1}, {2, 1},
        {0, 2}, {1, 2}, {2, 2}
    };

    IntegerPoint2D start_point = {-1, 2};

    std::list<IntegerMaze2D::MOVEMENT> movements = {
        IntegerMaze2D::MOVEMENT::RIGHT,
        IntegerMaze2D::MOVEMENT::RIGHT,
        IntegerMaze2D::MOVEMENT::DOWN,
        IntegerMaze2D::MOVEMENT::DOWN,
        IntegerMaze2D::MOVEMENT::DOWN,
        IntegerMaze2D::MOVEMENT::DOWN,
        IntegerMaze2D::MOVEMENT::DOWN,
        IntegerMaze2D::MOVEMENT::LEFT,
        IntegerMaze2D::MOVEMENT::LEFT,
        IntegerMaze2D::MOVEMENT::UP
    };

    IntegerMaze2D maze(points);

    IntegerPoint2D result = maze.navigate(start_point, movements);

    EXPECT_EQ(result, IntegerPoint2D(0, 1));
}

int main(int argc, char* argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}