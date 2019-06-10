#include <string>

#include <gtest/gtest.h>

#include <maze_movement.hpp>
#include <point.hpp>

TEST(GettersTests, DefaultConstructor) {
    IntegerPoint2D point;

    EXPECT_EQ(point.get_x(), 0);
    EXPECT_EQ(point.get_y(), 0);

    auto [x, y] = point.get();

    EXPECT_EQ(x, 0);
    EXPECT_EQ(y, 0);
}

TEST(GettersTests, ConstructorWithArgs) {
    IntegerPoint2D point(1, 1);

    EXPECT_EQ(point.get_x(), 1);
    EXPECT_EQ(point.get_y(), 1);

    auto [x, y] = point.get();

    EXPECT_EQ(x, 1);
    EXPECT_EQ(y, 1);
}

TEST(SettersTest, SetX) {
    IntegerPoint2D point;
    point.set_x(1);

    EXPECT_EQ(point.get_x(), 1);
}

TEST(SettersTest, SetY) {
    IntegerPoint2D point;
    point.set_y(1);

    EXPECT_EQ(point.get_y(), 1);
}

TEST(SettersTest, SetXY) {
    IntegerPoint2D point;
    point.set(1, 1);

    EXPECT_EQ(point.get_x(), 1);
    EXPECT_EQ(point.get_y(), 1);
}

TEST(HashTests, HashEQ) {
    IntegerPoint2D point1;
    IntegerPoint2D point2;
    IntegerPoint2D::Hash hash;

    EXPECT_EQ(hash(point1), hash(point2));
}

TEST(HashTests, HashNE) {
    IntegerPoint2D point1;
    IntegerPoint2D point2(1, 1);
    IntegerPoint2D::Hash hash;

    EXPECT_NE(hash(point1), hash(point2));
}

TEST(EQOperatorTests, EQTest) {
    IntegerPoint2D point1;
    IntegerPoint2D point2;

    EXPECT_TRUE(point1 == point2);
}

TEST(EQOperatorTests, NETest) {
    IntegerPoint2D point1;
    IntegerPoint2D point2(1, 1);

    EXPECT_FALSE(point1 == point2);
}

TEST(ToStreamOperatorTests, DefaultValue) {
    testing::internal::CaptureStdout();
    IntegerPoint2D point;
    std::cout << point;
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "(0,0)");
}

TEST(ToStreamOperatorTests, AnotherValue) {
    testing::internal::CaptureStdout();
    IntegerPoint2D point(1, 1);
    std::cout << point;
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "(1,1)");
}

int main(int argc, char* argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}