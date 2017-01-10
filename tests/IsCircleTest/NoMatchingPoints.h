//
// Created by test on 10.01.17.
//

#ifndef ORANGEBALL_NOMATCHINGPOINTS_H
#define ORANGEBALL_NOMATCHINGPOINTS_H
    TEST(isCircleTest, NoMatchingPoints){
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
#endif //ORANGEBALL_NOMATCHINGPOINTS_H
