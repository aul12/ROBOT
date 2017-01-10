#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"

using namespace cv;

int main(int argc, char** args){

    std::cout << "Generating contours out of given images:" << std::endl;
    for(int c=1; c<argc; c++){
        std::cout << "Img: " << args[c] << std::endl;

        Mat img = imread(args[c], CV_LOAD_IMAGE_GRAYSCALE);

        Canny(img, img, 50, 50*3, 3);

        std::vector<std::vector<Point>> contourPoints;
        std::vector<Vec4i> hierarchy;

        findContours(img, contourPoints, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

        for(int d=0; d<contourPoints.size(); d++){
            std::cout << "{" << std::endl;
            for(int e=0; e<contourPoints[d].size(); e++){
                if(e!=0)
                    std::cout << ", " << std::endl;
                std::cout << "Point(" << contourPoints[d][e].x << ", " << contourPoints[d][e].x <<  ")";
            }
            std::cout << std::endl << "}" << std::endl;
        }
        std::cout << std::endl << std::endl;
    }
}