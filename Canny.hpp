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
        //cvtColor(imgOriginal, imgBW, CV_BGR2GRAY);
        Mat planes[3];
        split(imgOriginal,planes);  // planes[2] is the red channel
        imgBW = planes[2];
        blur(imgBW, imgBW, Size(3,3), Point(-1, -1));

        Canny(imgBW, imgCanny, threshold, 3*threshold, 3);

        std::vector<std::vector<Point>> contourPoints;
        std::vector<Vec4i> hierarchy;

        findContours(imgCanny, contourPoints, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));


        imgCannyContours = Mat::zeros(imgOriginal.size(), CV_8UC3);

        cvtColor(imgBW, imgBW, COLOR_GRAY2BGR);

        std::cout <<  std::endl << std::endl;
        for( int i = 0; i< contourPoints.size(); i++ )
        {
            std::cout << "Obj: " << i << std::endl;

            if(crclfnd::isCircle(contourPoints[i])){
                drawContours(imgBW, contourPoints, i, Scalar(0, 255, 0), 2, 8, hierarchy, 0, Point());
            }else {
                drawContours(imgBW, contourPoints, i, Scalar(0, 0, 255), 1, 8, hierarchy, 0, Point());
            }
        }

        return imgBW;
    }
}

#endif //ORANGEBALL_CANNY_HPP
