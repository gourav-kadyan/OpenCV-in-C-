#include <iostream>
#include<opencv4/opencv2/opencv.hpp>

int main(int, char**){
    

    cv::Mat img = cv::Mat::zeros(1000,1000,CV_8UC3);

    cv::circle(img,cv::Point(500,500),70,cv::Scalar(255,255,255),cv::FILLED);

    //mercury
    cv::circle(img,cv::Point(500,500),120,cv::Scalar(255,255,255));
    cv::circle(img,cv::Point(500,620),20,cv::Scalar(155,55,255),cv::FILLED);

    //venus
    cv::circle(img,cv::Point(500,500),170,cv::Scalar(255,255,255));
    cv::circle(img,cv::Point(500,500-170),20,cv::Scalar(155,55,255),cv::FILLED);

    //earth
    cv::circle(img,cv::Point(500,500),220,cv::Scalar(255,255,255));
    cv::circle(img,cv::Point(500,500+220),20,cv::Scalar(155,55,255),cv::FILLED);

    //mars
    cv::circle(img,cv::Point(500,500),270,cv::Scalar(255,255,255));
    cv::circle(img,cv::Point(500,500-270),20,cv::Scalar(155,55,255),cv::FILLED);

    //jupitar
    cv::circle(img,cv::Point(500,500),350,cv::Scalar(255,255,255));
    cv::circle(img,cv::Point(500,500-350),50,cv::Scalar(155,55,255),cv::FILLED);

    //saturn
    cv::circle(img,cv::Point(500,500),400,cv::Scalar(255,255,255));
    cv::circle(img,cv::Point(500,500+400),20,cv::Scalar(155,55,255),cv::FILLED);

    //neptune
    cv::circle(img,cv::Point(500,500),450,cv::Scalar(255,255,255));
    cv::circle(img,cv::Point(500,500-450),20,cv::Scalar(155,55,255),cv::FILLED);

    //uranus
    cv::circle(img,cv::Point(500,500),500,cv::Scalar(255,255,255));
    cv::circle(img,cv::Point(500,500+500),20,cv::Scalar(155,55,255),cv::FILLED);


    cv::imshow("img",img);
    cv::waitKey(0);
    return 0;
}
