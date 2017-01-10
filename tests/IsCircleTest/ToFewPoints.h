//
// Created by test on 10.01.17.
//

#ifndef ORANGEBALL_TOFEWPOINTS_H
#define ORANGEBALL_TOFEWPOINTS_H

    TEST(isCircleTest, ToFewPoints){
        EXPECT_FALSE(crclfnd::isCircle({Point(0,0)}));
        EXPECT_FALSE(crclfnd::isCircle({Point(0,0), Point(0,0)}));
    }

#endif //ORANGEBALL_TOFEWPOINTS_H
