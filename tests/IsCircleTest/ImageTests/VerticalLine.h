//
// Created by test on 10.01.17.
//

#ifndef ORANGEBALL_VERTICALLINE_H
#define ORANGEBALL_VERTICALLINE_H
TEST(isCircleTest, VerticalLineImage){
    EXPECT_FALSE(crclfnd::isCircle({
           Point(285, 285),
           Point(283, 283),
           Point(283, 283),
           Point(284, 284),
           Point(300, 300),
           Point(300, 300),
           Point(299, 299)
   }));
}
#endif //ORANGEBALL_VERTICALLINE_H
