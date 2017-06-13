//
// Created by paul on 17.05.17.
//

#ifndef ORANGEBALL_FUSION_HPP
#define ORANGEBALL_FUSION_HPP

#include "opencv2/opencv.hpp"

namespace fusion{
    struct BallPosition{
        Point center;
        uint16_t radius;
        uint16_t value;
    };

    Mat getCanny(std::vector<CircleFinderResult> circleFinderResults, MatSize matSize){
        Mat result = Mat::zeros(matSize(), CV_8UC1);
        for(int c=0; c<circleFinderResults.size(); c++) {
            cv::circle(result, circleFinderResults[c].centre, circleFinderResults[c].radius,
                       circleFinderResults[c].circularity, -1);
        }

        return result;
    }

    BallPosition getPosition(bool cannyEnable, bool colorEnable,
                                std::vector<CircleFinderResult> circleFinderResults,
                                cv::Mat colourResults, cv::MatSize matSize, int fusionBias){
        cv::Size s = matSize();
        cv::Mat imgFinal = cv::Mat::zeros(s, CV_8UC1);

        cv::Mat imgCircleFinder = cv::Mat::zeros(s, CV_8UC1);
        if(cannyEnable){
            imgCircleFinder = getCanny(circleFinderResults, matSize);
        }

        if(!colorEnable){
            colourResults = cv::Mat::zeros(s, CV_8UC1);
        }

        addWeighted(imgCircleFinder, fusionBias/50.0, colourResults, (100-fusionBias)/50, 0, imgFinal);
        blur(imgFinal, imgFinal, Size(9, 9));

        uchar max = 0;
        bool objectFound = false;
        int xMax = 0, yMax = 0;
        for (int y = 0; y < imgFinal.rows; y++) {
            for (int x = 0; x < imgFinal.cols; x++) {
                uchar val = imgFinal.at<uchar>(Point(x, y));

                if (val > max) {
                    objectFound = true;
                    max = val;
                    xMax = x;
                    yMax = y;
                }
            }
        }

        int circleIndex = -1;
        if (objectFound) {
            for (int c = 0; c < circleFinderResults.size(); c++) {
                Point centre = circleFinderResults[c].centre;
                if (SQ(xMax - centre.x) + SQ(yMax - centre.y) < SQ(circleFinderResults[c].radius)) {
                    circle(imgFinal, centre, circleFinderResults[c].radius, 255, -1);
                    circleIndex = c;
                    break;
                }
            }
        }

        BallPosition result;

        if(circleIndex == -1){
            result.center.x = xMax;
            result.center.y = yMax;
            result.radius = 0;
        } else {
            result.center = circleFinderResults[circleIndex].centre;
            result.radius = circleFinderResults[circleIndex].radius;
        }
        result.value = max;

        return result;
    }
}

#endif //ORANGEBALL_FUSION_HPP
