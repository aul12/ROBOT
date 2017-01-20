/**
 * @file Canny.hpp
 * @author Paul Nykiel, Tim Luchterhand
 * @brief Detect features of the image by analysing the contours of the image
 */

#ifndef ORANGEBALL_CANNY_HPP
#define ORANGEBALL_CANNY_HPP

#include "Line.hpp"
#include "CircleFinder.hpp"
#include "debug.hpp"

using namespace cv;

/**
 * @brief Namespace containing all methods to manage the analysis of the image by analysing it's contours
 */
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

        dbg::printLn();

        for( int i = 0; i< contourPoints.size(); i++ )
        {
            dbg::printLn("Obj:" + i);

            CircleFinderResult result = crclfnd::isCircle(contourPoints[i]);
            if(result.isCircle){
                drawContours(imgBW, contourPoints, i, Scalar(0, 255, 0), 2, 8, hierarchy, 0, Point());
               /* line(imgBW, result.triangle[0], result.triangle[1], Scalar(255,0,0), 2, 8);
                line(imgBW, result.triangle[1], result.triangle[2], Scalar(255,0,0), 2, 8);
                line(imgBW, result.triangle[0], result.triangle[2], Scalar(255,0,0), 2, 8);*/
            }else {
                drawContours(imgBW, contourPoints, i, Scalar(0, 0, 255), 1, 8, hierarchy, 0, Point());
            }
            line(imgBW, result.triangle[0], result.triangle[1], Scalar(255,0,0), 2, 8);
            line(imgBW, result.triangle[1], result.triangle[2], Scalar(255,0,0), 2, 8);
            line(imgBW, result.triangle[0], result.triangle[2], Scalar(255,0,0), 2, 8);
        }

        return imgBW;
    }
}

#endif //ORANGEBALL_CANNY_HPP
