#include "gtest/gtest.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"

#include "../CircleFinder.hpp"


TEST(isCircleTest, toLessPoints){
    EXPECT_FALSE(crclfnd::isCircle({Point(0,0)}));
    EXPECT_FALSE(crclfnd::isCircle({Point(0,0), Point(0,0)}));
}

TEST(isCircleTest, noMatchingPoints){
    EXPECT_FALSE(crclfnd::isCircle({
        Point(0,0),
        Point(0,0),
        Point(0,0),
        Point(0,0),
        Point(0,0),
        Point(0,0),
        Point(0,0),
        Point(0,0),
        Point(0,0),
        Point(0,0)
    }));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
