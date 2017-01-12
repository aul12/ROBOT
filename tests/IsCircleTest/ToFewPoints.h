//
// Created by test on 10.01.17.
//

#ifndef ORANGEBALL_TOFEWPOINTS_H
#define ORANGEBALL_TOFEWPOINTS_H

    TEST(isCircleTest, ToFewPoints){
        EXPECT_FALSE(crclfnd::isCircle({Point(0,0)}).isCircle);
        EXPECT_FALSE(crclfnd::isCircle({Point(0,0), Point(0,0)}).isCircle);
    }

#endif //ORANGEBALL_TOFEWPOINTS_H
