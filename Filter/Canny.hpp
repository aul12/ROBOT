/**
 * @file Canny.hpp
 * @author Paul Nykiel, Tim Luchterhand
 * @brief Detect features of the image by analysing the contours of the image
 */

#ifndef ORANGEBALL_CANNY_HPP
#define ORANGEBALL_CANNY_HPP

#include "../Profiler.hpp"
#include "lib/Line.hpp"
#include "CircleFinder.hpp"
#include "../debug.hpp"


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

    /**
     * Factor to change the contrast of the color-filtered image. Values smaller 1 reduce the contrast,
     * values larger 1 enhance the contrast. If it is set to one the image won't get changed. 0 means the
     * complete image is gray. Negative numbers invert the image. 2 is a good value if both filters are combined.
     */
     int contrastFactor;


    Mat imgColourFiltered;

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
        crclfnd::init("../config/circleFinderConfig.xml");

        FileStorage fileStorage("../config/canny.xml", FileStorage::READ);

        threshold = fileStorage["threshold"];
        colorBias = fileStorage["colorBias"];
        contrastFactor = fileStorage["contrastFactor"];
    }


    /**
     * Write out all configuration data into the configuration file.
     */
    void close(){
        FileStorage fileStorage("../config/canny.xml", FileStorage::WRITE);

        fileStorage << "threshold" << threshold;
        fileStorage << "colorBias" << colorBias;
        fileStorage << "contrastFactor" << contrastFactor;

        fileStorage.release();
    }

    /**
     * Show the image and all trackbars for configuration in window
     * @param img the image which got created by run
     * @see run
     */
    void show(Mat img){
        namedWindow("CircleFinder", WINDOW_NORMAL);
        createTrackbar("Threshold", "CircleFinder", &threshold, 100);
        createTrackbar("Color bias", "CircleFinder", &colorBias, 100);
        createTrackbar("Contrast", "CircleFinder", &contrastFactor, 100);
        imshow("CircleFinder", img);

        namedWindow("Canny", WINDOW_NORMAL);
        imshow("Canny", imgColourFiltered);
    }

    /**
     * Run the canny algorithm on the image and detect circular objects
     * @param imgOriginal the image the algorithm should check
     * @return an image with debug information
     */
    std::vector<CircleFinderResult> run(Mat imgOriginal){
        PROF_START(Canny)
        // Define the necessary images
        Mat imgCanny, imgCannyContours;

        PROF_START(Canny_ColorFilter)
        // Apply a colour filter
        Mat green, red;
        extractChannel(imgOriginal, green, GREEN);
        extractChannel(imgOriginal, red, RED);
        bitwise_not(green, green);
        addWeighted(red,colorBias/100.0, green, 1-colorBias/100.0, 0, imgColourFiltered);

        // Blur the image to reduce noise
        blur(imgColourFiltered, imgColourFiltered, Size(3,3), Point(-1, -1));
        PROF_END(Canny_ColorFilter);

        PROF_START(Canny_Canny);
        // Get the contours with the canny algorithm
        Canny(imgColourFiltered, imgCanny, threshold, 3*threshold, 3);
        PROF_END(Canny_Canny)

        PROF_START(Canny_FindContours)
        std::vector<std::vector<Point> > contourPoints;
        std::vector<Vec4i> hierarchy;

        findContours(imgCanny, contourPoints, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

        imgCannyContours = Mat::zeros(imgOriginal.size(), CV_8UC3);

        cvtColor(imgColourFiltered, imgColourFiltered, COLOR_GRAY2BGR);
        PROF_END(Canny_FindContours)


        PROF_START(Canny_CircleFinder)
        Mat imgResult = Mat::zeros(imgOriginal.size(), CV_8UC1);

        std::vector<CircleFinderResult> results;
        for( int i = 0; i< contourPoints.size(); i++ )
        {
            CircleFinderResult result = crclfnd::isCircle(contourPoints[i]);
            results.push_back(result);
            drawContours(imgColourFiltered, contourPoints, i, Scalar(0, 0, 255), 1, 8, hierarchy, 0, Point());

            line(imgColourFiltered, result.triangle[0], result.triangle[1], Scalar(255,0,0), 2, 8);
            line(imgColourFiltered, result.triangle[1], result.triangle[2], Scalar(255,0,0), 2, 8);
            line(imgColourFiltered, result.triangle[0], result.triangle[2], Scalar(255,0,0), 2, 8);
        }
        PROF_END(Canny_CircleFinder)
        PROF_END(Canny)
        return results;
    }
}

#endif //ORANGEBALL_CANNY_HPP
