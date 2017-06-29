/**
 * @file ColourBased.hpp
 * @author Paul Nykiel, Tim Luchterhand
 * @brief Detect the orange ball solely by the color
 */

#ifndef ORANGEBALL_COLOURBASED_HPP
#define ORANGEBALL_COLOURBASED_HPP
using namespace cv;

namespace clr{
    int hue = 0;
    int minHue, maxHue;
    int minSaturation, maxSaturation;
    int minValue, maxValue;
    int minSize;

    void init(){
        FileStorage fileStorage("../config/colourBased.xml", FileStorage::READ);

        minHue = fileStorage["minHue"];
        maxHue = fileStorage["maxHue"];
        minSaturation = fileStorage["minSaturation"];
        maxSaturation = fileStorage["maxSaturation"];
        minValue = fileStorage["minValue"];
        maxValue = fileStorage["maxValue"];
    }

    void close(){
        FileStorage fileStorage("../config/colourBased.xml", FileStorage::WRITE);

        fileStorage << "minHue" << minHue;
        fileStorage << "maxHue" << maxHue;
        fileStorage << "minSaturation" << minSaturation;
        fileStorage << "maxSaturation" << maxSaturation;
        fileStorage << "minValue" << minValue;
        fileStorage << "maxValue" << maxValue;

        fileStorage.release();
    }

    void show(Mat img){
        namedWindow("ColourBased", WINDOW_NORMAL);

        createTrackbar("Hue", "ColourBased", &hue, 179);

        imshow("ColourBased", img);
    }

    Mat run(Mat imgOriginal){
        Mat imgHSV, imgColorThresholded, imgLowRes;

        resize(imgOriginal, imgLowRes, Size(80, 60));
        cvtColor(imgLowRes, imgHSV, COLOR_BGR2HSV);
        
        imgColorThresholded = Mat::zeros(imgLowRes.size(), CV_8UC1);

        //Abweichung vom gesetzten Hue-Wert berechnen und eintragen
        for(int y = 0; y < imgHSV.rows; y++){
            for(int x = 0; x < imgHSV.cols; x++){
                Vec3b val = imgHSV.at<Vec3b>(Point(x, y));
                int hueDifference = abs(val[0] - hue);
                if(hueDifference > 90)
                    hueDifference = 180 - hueDifference;
                imgColorThresholded.at<uchar>(y, x) = (uchar) ((90 - hueDifference) * (val[1] / 255.0) * 1.41);
            }
        }

        resize(imgColorThresholded, imgColorThresholded, imgOriginal.size());
        return imgColorThresholded;
    }
}



#endif //ORANGEBALL_COLOURBASED_HPP
