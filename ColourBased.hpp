/**
 * @file ColourBased.hpp
 * @author Paul Nykiel, Tim Luchterhand
 * @brief Detect the orange ball solely by the color
 */

#ifndef ORANGEBALL_COLOURBASED_HPP
#define ORANGEBALL_COLOURBASED_HPP
using namespace cv;

namespace clr{
    int minHue, maxHue;
    int minSaturation, maxSaturation;
    int minValue, maxValue;
    int minSize;

    void init(){
        FileStorage fileStorage("colourBased.xml", FileStorage::READ);

        minHue = fileStorage["minHue"];
        maxHue = fileStorage["maxHue"];
        minSaturation = fileStorage["minSaturation"];
        maxSaturation = fileStorage["maxSaturation"];
        minValue = fileStorage["minValue"];
        maxValue = fileStorage["maxValue"];
    }

    void close(){
        FileStorage fileStorage("colourBased.xml", FileStorage::WRITE);

        fileStorage << "minHue" << minHue;
        fileStorage << "maxHue" << maxHue;
        fileStorage << "minSaturation" << minSaturation;
        fileStorage << "maxSaturation" << maxSaturation;
        fileStorage << "minValue" << minValue;
        fileStorage << "maxValue" << maxValue;

        fileStorage.release();
    }

    void show(Mat img){
        namedWindow("ColourBased", CV_WINDOW_AUTOSIZE);

        createTrackbar("Minimum Hue", "ColourBased", &minHue, 179);
        createTrackbar("Maximum  Hue", "ColourBased", &maxHue, 179);

        createTrackbar("Minimum Saturation", "ColourBased", &minSaturation, 255);
        createTrackbar("Maximum  Saturation", "ColourBased", &maxSaturation, 255);

        createTrackbar("Minimum Value", "ColourBased", &minValue, 255);
        createTrackbar("Maximum  Value", "ColourBased", &maxValue, 255);

        createTrackbar("MinSize", "ColourBased", &minSize, 100000);

        imshow("ColourBased", img);
    }

    bool compareContourAreas(std::vector<cv::Point> contour1, std::vector<cv::Point> contour2){
        double i = fabs(contourArea(cv::Mat(contour1)));
        double j = fabs(contourArea(cv::Mat(contour2)));
        return (i > j);
    }

    Mat run(Mat imgOriginal){
        Mat imgHSV, imgColorThresholded;
        cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV);

        GaussianBlur(imgHSV,imgHSV, Size(3,3), 2,2);
        //Pixelweise überprüfen ob ihn Grenzen
        inRange(imgHSV, Scalar(minHue, minSaturation, minValue), Scalar(maxHue, maxSaturation, maxValue), imgColorThresholded);

        //Löcher füllen/Rauschen glätten
        erode(imgColorThresholded, imgColorThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
        dilate( imgColorThresholded, imgColorThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

        //Konturen finden
        std::vector<std::vector<Point>> colorContours;
        std::vector<Vec4i> colorHierarchy;
        findContours( imgColorThresholded, colorContours, colorHierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(0, 0) );

        //Flächen nach Größe sortieren
        if(colorContours.size()>0)
            sort(colorContours.begin(), colorContours.end(), compareContourAreas);

        //Konturen zeichnen
        imgColorThresholded = Mat::zeros(imgOriginal.size(), CV_8UC1 );
        for( size_t i = 0; i< colorContours.size(); i++ )
        {
            drawContours(imgColorThresholded, colorContours, (int)i, 100, CV_FILLED, 8, colorHierarchy, 0, Point());
        }

        if(colorContours.size()>0) {
            //Größte Kontur hervorheben
            if (contourArea(colorContours[0]) > minSize)
                drawContours(imgColorThresholded, colorContours, 0, 255, CV_FILLED, 8, colorHierarchy, 0, Point());
        }

        return imgColorThresholded;
    }
}



#endif //ORANGEBALL_COLOURBASED_HPP
