//
// Created by paul on 17.05.17.
//

#ifndef ORANGEBALL_FUSION_HPP
#define ORANGEBALL_FUSION_HPP

#include "opencv2/opencv.hpp"

#define MEM_SIZE 5
#define MAX_SEARCH_PREC 8   ///< Grid to be searched to find maximum

namespace fusion{
    struct BallPosition{
        Point center;
        uint16_t radius;
        uint16_t value;
    };

    BallPosition lastPosition[MEM_SIZE];
    int head = 0;

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
                                cv::Mat colourResults, cv::MatSize matSize, int fusionBias,
                                bool guiEnable){
        cv::Size s = matSize();
        cv::Mat imgFinal = cv::Mat::zeros(s, CV_8UC1);

        cv::Mat imgCircleFinder = cv::Mat::zeros(s, CV_8UC1);
        if(cannyEnable){
            imgCircleFinder = getCanny(circleFinderResults, matSize);
        }

        if(!colorEnable){
            colourResults = cv::Mat::zeros(s, CV_8UC1);
        }

        addWeighted(imgCircleFinder, fusionBias/50.0, colourResults, (100-fusionBias)/50.0, 0, imgFinal);

        Mat imgLast = Mat::zeros(s, CV_8UC1);
        for(int c=0; c<MEM_SIZE; c++){
            circle(imgLast, lastPosition[(c+head)%MEM_SIZE].center,
                lastPosition[(c+head)%MEM_SIZE].radius, lastPosition[(c+head)%MEM_SIZE].value/(log(c+2)), -1);
        }

        addWeighted(imgFinal, 1, imgLast, 1, 0, imgFinal);

        blur(imgFinal, imgFinal, Size(9, 9));

        if(guiEnable){
            namedWindow("Final", WINDOW_NORMAL);
            imshow("Final", imgFinal);

        }

        uchar max = 0;
        bool objectFound = false;
        int xMax = 0, yMax = 0;
        for (int y = 0; y < imgFinal.rows; y+=MAX_SEARCH_PREC) {
            for (int x = 0; x < imgFinal.cols; x+=MAX_SEARCH_PREC) {
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

        head = (head-1+MEM_SIZE)%MEM_SIZE;
        lastPosition[head] = result;

        return result;
    }
}

#endif //ORANGEBALL_FUSION_HPP
