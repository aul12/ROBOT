#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"

using namespace cv;


String getContoursString(Mat img){
    String res = "\t\t{\n";

    Canny(img, img, 50, 50*3, 3);

    std::vector<std::vector<Point>> contourPoints;
    std::vector<Vec4i> hierarchy;

    findContours(img, contourPoints, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

    if(contourPoints.size()!=1){
        res += "\t\t#error Image more than one/no contours";
    }else{
        for(int c=0; c<contourPoints[0].size(); c++){
            if(c!=0)
                res +=  ",\n";

            res += format("\t\tPoint(%d,%d)", contourPoints[0][c].x, contourPoints[0][c].y);
        }
    }


    return res + "}";
}

int main(int argc, char** args){
    if(argc < 2)
        return -1;
    std::cout << "TEST(isCircleTest, " << args[1] << "){" << std::endl;
    std::cout << "\t#warning Change Value!" << std::endl;
    std::cout << "\tEXPECT_TRUE(crclfnd::isCircle(" << std::endl;
    std::cout << getContoursString(imread(args[1], CV_LOAD_IMAGE_GRAYSCALE));
}