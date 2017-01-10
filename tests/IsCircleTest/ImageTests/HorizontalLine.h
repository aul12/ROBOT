//
// Created by test on 10.01.17.
//

#ifndef ORANGEBALL_HORIZONTALLINE_H
#define ORANGEBALL_HORIZONTALLINE_H
TEST(isCircleTest, HorizontalLineImage){
    EXPECT_FALSE(crclfnd::isCircle({
               Point(94, 94),
               Point(92, 92),
               Point(93, 93),
               Point(601, 601),
               Point(601, 601),
               Point(600, 600)
       }));
}
#endif //ORANGEBALL_HORIZONTALLINE_H
