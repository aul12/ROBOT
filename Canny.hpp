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
    /**
     * Lower canny threshold can be adjusted with a slider. The lower the threshold the more edges get detected
     * but there is more noise as well.
     */
    int threshold;
    /**
     * The bias of the color filter. 0 means the inverted green filter only, 100 means the red filter only.
     * A good value is at approximately 45.
     */
    int colorBias;

    /// Enum with shortcuts for the different colour planes of a BGR image
    enum COLORS_BGR{
        BLUE = 0,
        GREEN = 1,
        RED = 2
    };


    /**
     * Initialise all configuration data required for the algorithm. This is done by reading a configuration file.
     */
    void init(){
        FileStorage fileStorage("canny.xml", FileStorage::READ);

        threshold = fileStorage["threshold"];
        colorBias = fileStorage["colorBias"];
    }


    /**
     * Write out all configuration data into the configuration file.
     */
    void close(){
        FileStorage fileStorage("canny.xml", FileStorage::WRITE);

        fileStorage << "threshold" << threshold;
        fileStorage << "colorBias" << colorBias;

        fileStorage.release();
    }

    /**
     * Show the image and all trackbars for configuration in window
     * @param img the image which got created by run
     * @see run
     */
    void show(Mat img){
        namedWindow("Canny", CV_WINDOW_AUTOSIZE);
        createTrackbar("Threshold", "Canny", &threshold, 100);
        createTrackbar("Color bias", "Canny", &colorBias, 100);
        imshow("Canny", img);
    }

    /**
     * Run the canny algorithm on the image and detect circular objects
     * @param imgOriginal the image the algorithm should check
     * @return an image with debug information
     */
    Mat run(Mat imgOriginal){
        // Define the necessary images
        Mat imgColourFiltered, imgCanny, imgCannyContours;

        // Apply a colour filter
        Mat planes[3];
        split(imgOriginal,planes);  // Split image into three images one for each color pane
        bitwise_not(planes[GREEN], planes[GREEN]);  // Invert the image
        addWeighted(planes[RED], colorBias/100.0, planes[GREEN], 1-colorBias/100.0, 0, imgColourFiltered);

        imgColourFiltered -= 127;
        imgColourFiltered *= 2;
        imgColourFiltered += 127;

        // Blur the image to reduce noise
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
