#include<iostream>
#include<opencv4/opencv2/opencv.hpp>

using namespace cv;

int main()
{

    VideoCapture cap(0);

    Mat img;

    while(true)
    {
        cap >> img;

        // cvtColor(img,img,COLOR_BGR2GRAY);
        Mat ker = getStructuringElement(MORPH_CROSS,Size(5,5));
        morphologyEx(img,img,MORPH_CLOSE,ker);

        imshow("",img);
        // imshow("1",img);

        char wai = (char)waitKey(25);

        if(wai == 27  || wai == ('q'))
        {
            break;
        }



    }

    cap.release();

    return (EXIT_SUCCESS);
}