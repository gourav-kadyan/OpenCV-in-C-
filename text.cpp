#include<iostream>
#include<opencv4/opencv2/opencv.hpp>

int main()
{

    cv::Mat img = cv::Mat::zeros(cv::Size(500,500),CV_8UC3);

    cv::putText(img,"hello duniya",cv::Point(50,50),cv::FONT_HERSHEY_COMPLEX,1,cv::Scalar(255,255,255),3);
    cv::imshow("img",img);
    cv::waitKey(0);

    return 0;
}
