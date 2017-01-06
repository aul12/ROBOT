#ifndef ORANGEBALL_CANNY_HPP
#define ORANGEBALL_CANNY_HPP

#include "CircleFinder.hpp"

using namespace cv;

namespace cnny{
    int threshold;

    void init(){
        FileStorage fileStorage("canny.xml", FileStorage::READ);

        threshold = fileStorage["threshold"];
    }

    void close(){
        FileStorage fileStorage("canny.xml", FileStorage::WRITE);

        fileStorage << "threshold" << threshold;

        fileStorage.release();
    }

    void show(Mat img){
        namedWindow("Canny", CV_WINDOW_AUTOSIZE);
        createTrackbar("Threshold", "Canny", &threshold, 100);

        imshow("Canny", img);
    }

    Mat run(Mat imgOriginal){
        Mat imgBW, imgCanny, imgCannyContours;
        cvtColor(imgOriginal, imgBW, CV_BGR2GRAY);
        Canny(imgBW, imgCanny, threshold, 3*threshold, 3);

        std::vector<std::vector<Point>> contourPoints;
        std::vector<Vec4i> hierarchy;

        findContours(imgCanny, contourPoints, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));


        imgCannyContours = Mat::zeros(imgOriginal.size(), CV_8UC3);

        std::cout <<  std::endl << std::endl;
        for( int i = 0; i< contourPoints.size(); i++ )
        {
            std::cout << "Obj: " << i << std::endl;


            if(crclfnd::isCircle(contourPoints[i])){
                drawContours(imgCannyContours, contourPoints, i, Scalar(0, 255, 0), 1, 8, hierarchy, 0, Point());
            }else {
                drawContours(imgCannyContours, contourPoints, i, Scalar(0, 0, 255), 1, 8, hierarchy, 0, Point());
            }
        }

        return imgCannyContours;
    }
}

#endif //ORANGEBALL_CANNY_HPP
