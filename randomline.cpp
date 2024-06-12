#include<iostream>

#include<opencv4/opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat img = Mat::zeros(Size(500,500),CV_8UC3);

    RNG r;
    int val = r.uniform(10, 30);
    for(int i=0;i<100;i++)
    {
        line(img,Point(r.uniform(0,img.cols),r.uniform(0,img.rows)),Point(r.uniform(0,img.cols),r.uniform(0,img.rows)),Scalar(r.uniform(0,256),r.uniform(0,256),r.uniform(0,256)),r.uniform(2,10));
        Point pt;
        pt.x = r.uniform(0,img.cols);
        pt.y= r.uniform(0,img.rows);
        circle(img,pt,r.uniform(0,100),Scalar(r.uniform(0,256),r.uniform(0,256),r.uniform(0,256)),-1);
        waitKey(100);
        imshow("random line",img);
        waitKey(100);
    }
    imshow("random line",img);
    waitKey();
    return 0;
}