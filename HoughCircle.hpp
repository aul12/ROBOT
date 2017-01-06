#ifndef ORANGEBALL_HOUGHCIRCLE_HPP
#define ORANGEBALL_HOUGHCIRCLE_HPP
using namespace cv;

namespace hghc{
    void init(){

    }

    void close(){

    }

    void show(Mat img){
        imshow("HoughCircle", img);
    }

    Mat run(Mat imgOriginal){
        Mat imgBW, imgHough;
        cvtColor( imgOriginal, imgBW, CV_BGR2GRAY );
        GaussianBlur( imgBW, imgBW, Size(5, 5), 2, 2 );

        std::vector<Vec3f> circles;

        HoughCircles( imgBW, circles, CV_HOUGH_GRADIENT, 1, imgBW.rows/8, 200, 100, 0, 0 );

        cvtColor(imgBW, imgBW, CV_GRAY2BGR);

        imgHough = Mat::zeros(imgOriginal.rows, imgOriginal.cols, CV_8UC1);
        for( size_t i = 0; i < circles.size(); i++ )
        {
            Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
            int radius = cvRound(circles[i][2]);
            circle( imgHough, center, radius, Scalar(255,255,255), -1, 8, 0 );
        }
        return imgHough;
    }
}

#endif //ORANGEBALL_HOUGHCIRCLE_HPP
