#include "gtest/gtest.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/videoio.hpp"

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

TEST(isCircleTest, isCircle){
    EXPECT_TRUE(crclfnd::isCircle({
           Point(50,0),
           Point(20,20),
           Point(0,50),
           Point(-20,20),
           Point(-50,0),
           Point(-40,-10),
           Point(-10,-40),
           Point(0,-50),
           Point(10,-40),
           Point(40,-10)
   }));
}

int main(int argc, char **argv) {
      ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
