#include <iostream>
#include <opencv4/opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat img = imread("messi5.jpg", IMREAD_COLOR);
    Mat grayImg, binaryImg;

    cvtColor(img, grayImg, COLOR_BGR2GRAY);
    threshold(grayImg, binaryImg, 60, 255, THRESH_BINARY);

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(binaryImg, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);

    Mat img_copy = img.clone();
    drawContours(img_copy, contours,-1, Scalar(0, 100, 255),2);

    imshow("Image", img);
    imshow("GrayImage", grayImg);
    imshow("BinaryImage", binaryImg);
    imshow("Contour Image", img_copy);
    waitKey(0);

    return 0;
}