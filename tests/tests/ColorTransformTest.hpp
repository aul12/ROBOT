//
// Created by paul on 30.01.17.
//

#ifndef ORANGEBALL_COLORTRANSFORMTEST_HPP
#define ORANGEBALL_COLORTRANSFORMTEST_HPP


TEST(ColorTransFormTest, RedTest){
    EXPECT_NE(clrTrfrm::::transformColor({255, 0, 0}), 255/3);
}

#endif //ORANGEBALL_COLORTRANSFORMTEST_HPP
