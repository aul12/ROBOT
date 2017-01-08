#include "gtest/gtest.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"

#include "../CircleFinder.hpp"


bool crclfnd::isCircle(std::vector<Point> points);

std::vector<Point> testPoints = {Point(0,0)};

TEST(isCircleTest, toLessPoints){
    EXPECT_FALSE(crclfnd::isCircle(testPoints));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
