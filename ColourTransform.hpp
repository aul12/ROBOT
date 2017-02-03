//
// Created by paul on 03.02.17.
//

#ifndef ORANGEBALL_COLOURTRANSFORM_HPP
#define ORANGEBALL_COLOURTRANSFORM_HPP

namespace clrTrfrm{
    const int hueMax = 14;
    const int satMax = 255;
    const int widthSaturation = SQ(10);
    const int widthHue = SQ(10);
    const int precision = 2;

    enum HSV{
        HUE = 0,
        SATURATION = 1,
        VALUE = 2
    };

    uchar transformColor(Vec3b color){
        /*if(color[1] < 10){
            return 0;
        }else if(color[2] < 0){
            return 0;
        }else if(color[0] > 42){
            return 0;
        }else{
            return color[2];
        }*/
        double dist = sqrt(SQ(hueMax-color[HUE])/widthHue + SQ(satMax-color[SATURATION])/widthSaturation);

        double fac = max(1-pow(dist,precision), 0.0);

        return color[VALUE] * fac;
    }
}

#endif //ORANGEBALL_COLOURTRANSFORM_HPP
