#include<iostream>
#include<opencv4/opencv2/opencv.hpp>
#include<vector>


int main(int argc, char const *argv[])
{
    /* code */

    cv::Mat img = cv::Mat::zeros(cv::Size(500,500),CV_8UC3);
    std::vector<cv::Point> v;
    v.push_back(cv::Point(50,20));
    v.push_back(cv::Point(250,20));
    v.push_back(cv::Point(240,120));
    v.push_back(cv::Point(150,150));
    v.push_back(cv::Point(60,120));
    cv::polylines(img,v,true,cv::Scalar(0,255,0),3);
    cv::fillPoly(img,v,cv::Scalar(250,70,250));

    cv::imshow("sigma",img);
    cv::waitKey(0);

    return 0;
}
