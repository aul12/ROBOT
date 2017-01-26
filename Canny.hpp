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

    enum COLORS{
        BLUE = 0,
        GREEN = 1,
        RED = 2
    };

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
        // Define the necessary images
        Mat imgColourFiltered, imgCanny, imgCannyContours;

        // Apply the colour filter
        Mat planes[3];
        split(imgOriginal,planes);  // Split image into three images one for each color pane
        bitwise_not(planes[GREEN], planes[GREEN]);  // Invert the image
        addWeighted(planes[RED], 0.6, planes[GREEN], 0.4, 0, imgColourFiltered);

        blur(imgColourFiltered, imgColourFiltered, Size(3,3), Point(-1, -1));


        // Get the contours with the canny algorithm
        Canny(imgColourFiltered, imgCanny, threshold, 3*threshold, 3);

        std::vector<std::vector<Point>> contourPoints;
        std::vector<Vec4i> hierarchy;

        findContours(imgCanny, contourPoints, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));


        imgCannyContours = Mat::zeros(imgOriginal.size(), CV_8UC3);

        cvtColor(imgColourFiltered, imgColourFiltered, COLOR_GRAY2BGR);


        for( int i = 0; i< contourPoints.size(); i++ )
        {
            CircleFinderResult result = crclfnd::isCircle(contourPoints[i]);
            if(result.isCircle){
                drawContours(imgColourFiltered, contourPoints, i, Scalar(0, 255, 0), 2, 8, hierarchy, 0, Point());
            }else {
                drawContours(imgColourFiltered, contourPoints, i, Scalar(0, 0, 255), 1, 8, hierarchy, 0, Point());
            }

            line(imgColourFiltered, result.triangle[0], result.triangle[1], Scalar(255,0,0), 2, 8);
            line(imgColourFiltered, result.triangle[1], result.triangle[2], Scalar(255,0,0), 2, 8);
            line(imgColourFiltered, result.triangle[0], result.triangle[2], Scalar(255,0,0), 2, 8);
        }

        return imgColourFiltered;
    }
}

#endif //ORANGEBALL_CANNY_HPP
