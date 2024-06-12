#include<iostream>
#include<opencv4/opencv2/opencv.hpp>

using namespace cv;

void Happy(Mat& img, RNG& r)
{

    //Happy 
    // cv::line(img,cv::Point(400,620),cv::Point(600,620),cv::Scalar(0,0,0),2);
    // cv::Mat img = cv::Mat::zeros(1000,1000,CV_8UC3);

    //structure
    // cv::circle(img,cv::Point(500,500),250,cv::Scalar(0,255,255),2);
    Point pt;
    pt.x = r.uniform(0,img.cols);
    pt.y = r.uniform(0,img.rows);
    int rad = r.uniform(50,250);
    cv::circle(img,pt,rad,Scalar(r.uniform(0,256),r.uniform(0,256),r.uniform(0,256)),-1);

    //eyes
    Point eye1;
    eye1.x = int(pt.x - (rad*0.6));
    eye1.y = int(pt.y - (rad*0.48));
    Point eye2;
    eye2.x = int(pt.x + (rad*0.6));
    eye2.y = int(pt.y - (rad*0.48));
    
    
    // cv::circle(img,cv::Point(400,370),20,cv::Scalar(0,0,0),2);
    cv::circle(img,eye1,int(rad -rad*0.92),Scalar(0,0,0),-1);
    // cv::circle(img,cv::Point(600,370),20,cv::Scalar(0,0,0),2);
    cv::circle(img,eye2,int(rad -rad*0.92),Scalar(0,0,0),-1);
    cv::ellipse(img,cv::Point(pt.x,int(pt.y + int(rad*0.52))),Size(int(rad - rad*0.6),int(rad - rad*0.8)),0,0,180,cv::Scalar(0,0,255),-1);

    // cv::imshow("Happy",img);
    // cv::waitKey(0);
}


void Sad(Mat& img, RNG& r) {
    Point pt;
    pt.x = r.uniform(0, img.cols);
    pt.y = r.uniform(0, img.rows);
    int rad = r.uniform(50, 250);
    cv::circle(img, pt, rad, Scalar(r.uniform(0, 256), r.uniform(0, 256), r.uniform(0, 256)), -1);

    Point eye1, eye2;
    eye1.x = int(pt.x - (rad * 0.6));
    eye1.y = int(pt.y - (rad * 0.48));
    eye2.x = int(pt.x + (rad * 0.6));
    eye2.y = int(pt.y - (rad * 0.48));

    cv::circle(img, eye1, int(rad * 0.08), Scalar(0, 0, 0), -1);
    cv::circle(img, eye2, int(rad * 0.08), Scalar(0, 0, 0), -1);
    cv::ellipse(img, Point(pt.x, int(pt.y + int(rad * 0.52))), Size(int(rad * 0.4), int(rad * 0.2)), 0, 0, -180, Scalar(0, 0, 0), -1);
}

void Confuse(Mat& img, RNG& r) {
    Point pt;
    pt.x = r.uniform(0, img.cols);
    pt.y = r.uniform(0, img.rows);
    int rad = r.uniform(50, 250);
    cv::circle(img, pt, rad, Scalar(r.uniform(0, 256), r.uniform(0, 256), r.uniform(0, 256)), -1);

    Point eye1, eye2;
    eye1.x = int(pt.x - (rad * 0.6));
    eye1.y = int(pt.y - (rad * 0.48));
    eye2.x = int(pt.x + (rad * 0.6));
    eye2.y = int(pt.y - (rad * 0.48));

    cv::circle(img, eye1, int(rad * 0.08), Scalar(0, 0, 0), -1);
    cv::circle(img, eye2, int(rad * 0.08), Scalar(0, 0, 0), -1);
    cv::line(img, Point(pt.x - int(rad * 0.4), pt.y + int(rad * 0.4)), Point(pt.x + int(rad * 0.4), pt.y + int(rad * 0.4)), Scalar(0, 0, 0), 3);
}

void Smile(Mat& img, RNG& r) {
    Point pt;
    pt.x = r.uniform(0, img.cols);
    pt.y = r.uniform(0, img.rows);
    int rad = r.uniform(50, 250);
    cv::circle(img, pt, rad, Scalar(r.uniform(0, 256), r.uniform(0, 256), r.uniform(0, 256)), -1);

    Point eye1, eye2;
    eye1.x = int(pt.x - (rad * 0.6));
    eye1.y = int(pt.y - (rad * 0.48));
    eye2.x = int(pt.x + (rad * 0.6));
    eye2.y = int(pt.y - (rad * 0.48));

    cv::circle(img, eye1, int(rad * 0.08), Scalar(0, 0, 0), -1);
    cv::circle(img, eye2, int(rad * 0.08), Scalar(0, 0, 0), -1);
    cv::ellipse(img, Point(pt.x, int(pt.y + int(rad * 0.52))), Size(int(rad * 0.4), int(rad * 0.2)), 0, 0, 180, Scalar(0, 0, 255), 4);
}

void Cry(Mat& img, RNG& r) {
    Point pt;
    pt.x = r.uniform(0, img.cols);
    pt.y = r.uniform(0, img.rows);
    int rad = r.uniform(50, 250);
    cv::circle(img, pt, rad, Scalar(r.uniform(0, 256), r.uniform(0, 256), r.uniform(0, 256)), -1);

    Point eye1, eye2;
    eye1.x = int(pt.x - (rad * 0.6));
    eye1.y = int(pt.y - (rad * 0.48));
    eye2.x = int(pt.x + (rad * 0.6));
    eye2.y = int(pt.y - (rad * 0.48));

    cv::circle(img, eye1, int(rad * 0.08), Scalar(0, 0, 0), -1);
    cv::circle(img, eye2, int(rad * 0.08), Scalar(0, 0, 0), -1);
    cv::ellipse(img, Point(pt.x, int(pt.y + int(rad * 0.52))), Size(int(rad * 0.4), int(rad * 0.2)), 0, 0, 360, Scalar(0, 0, 255), -1);

    // Adding tears
    cv::circle(img, Point(eye1.x, eye1.y + int(rad * 0.1)), int(rad * 0.04), Scalar(255, 0, 0), -1);
    cv::circle(img, Point(eye1.x, eye1.y + int(rad * 0.2)), int(rad * 0.04), Scalar(255, 0, 0), -1);
    cv::circle(img, Point(eye2.x, eye2.y + int(rad * 0.1)), int(rad * 0.04), Scalar(255, 0, 0), -1);
    cv::circle(img, Point(eye2.x, eye2.y + int(rad * 0.2)), int(rad * 0.04), Scalar(255, 0, 0), -1);
}

// void Sad(Mat &img)
// {
//     // cv::Mat img = cv::Mat::zeros(1000,1000,CV_8UC3);

//     //structure
//     cv::circle(img,cv::Point(500,500),250,cv::Scalar(0,255,255),2);
//     cv::circle(img,cv::Point(500,500),250,cv::Scalar(0,255,255),cv::FILLED);

//     //eyes
//     cv::circle(img,cv::Point(400,370),20,cv::Scalar(0,0,0),2);
//     cv::circle(img,cv::Point(400,370),20,cv::Scalar(0,0,0),cv::FILLED);
//     cv::circle(img,cv::Point(600,370),20,cv::Scalar(0,0,0),2);
//     cv::circle(img,cv::Point(600,370),20,cv::Scalar(0,0,0),cv::FILLED);
//     cv::ellipse(img,cv::Point(500,620),cv::Size(100,50),180,0,180,cv::Scalar(0,0,0),2);
//     cv::imshow("Sad",img);
//     cv::waitKey(0);
// }

// void Confuse(Mat &img)
// {

//     // cv::Mat img = cv::Mat::zeros(1000,1000,CV_8UC3);

//     //structure
//     cv::circle(img,cv::Point(500,500),250,cv::Scalar(0,255,255),2);
//     cv::circle(img,cv::Point(500,500),250,cv::Scalar(0,255,255),cv::FILLED);

//     //eyes
//     cv::circle(img,cv::Point(400,370),20,cv::Scalar(0,0,0),2);
//     cv::circle(img,cv::Point(400,370),20,cv::Scalar(0,0,0),cv::FILLED);
//     cv::circle(img,cv::Point(600,370),20,cv::Scalar(0,0,0),2);
//     cv::circle(img,cv::Point(600,370),20,cv::Scalar(0,0,0),cv::FILLED);
//     cv::line(img,cv::Point(400,600),cv::Point(600,600),cv::Scalar(0,0,0),3);

//     cv::imshow("confuse",img);
//     cv::waitKey(0);

// }

// void Smile(Mat &img)
// {

//     // cv::Mat img = cv::Mat::zeros(1000,1000,CV_8UC3);

//     //structure
//     cv::circle(img,cv::Point(500,500),250,cv::Scalar(0,255,255),2);
//     cv::circle(img,cv::Point(500,500),250,cv::Scalar(0,255,255),cv::FILLED);

//     //eyes
//     cv::circle(img,cv::Point(400,370),20,cv::Scalar(0,0,0),2);
//     cv::circle(img,cv::Point(400,370),20,cv::Scalar(0,0,0),cv::FILLED);
//     cv::circle(img,cv::Point(600,370),20,cv::Scalar(0,0,0),2);
//     cv::circle(img,cv::Point(600,370),20,cv::Scalar(0,0,0),cv::FILLED);
//     cv::ellipse(img,cv::Point(500,620),cv::Size(100,50),0,0,180,cv::Scalar(0,0,255),4);

//     cv::imshow("Smile",img);
//     cv::waitKey(0);

// }

// void Cry(Mat& img)
// {
//     // cv::Mat img = cv::Mat::zeros(1000,1000,CV_8UC3);

//     //structure
//     cv::circle(img,cv::Point(500,500),250,cv::Scalar(0,255,255),2);
//     cv::circle(img,cv::Point(500,500),250,cv::Scalar(0,255,255),cv::FILLED);

//     //eyes
//     cv::circle(img,cv::Point(400,370),20,cv::Scalar(0,0,0),2);
//     cv::circle(img,cv::Point(400,370),20,cv::Scalar(0,0,0),cv::FILLED);
//     cv::circle(img,cv::Point(600,370),20,cv::Scalar(0,0,0),2);
//     cv::circle(img,cv::Point(600,370),20,cv::Scalar(0,0,0),cv::FILLED);
//     cv::ellipse(img,cv::Point(500,620),cv::Size(100,50),0,0,360,cv::Scalar(0,0,255),-1);
//     cv::circle(img,cv::Point(400,410),10,cv::Scalar(255,0,0),2);
//     cv::circle(img,cv::Point(400,410),10,cv::Scalar(255,0,0),cv::FILLED);
//     cv::circle(img,cv::Point(600,440),10,cv::Scalar(255,0,0),2);
//     cv::circle(img,cv::Point(600,440),10,cv::Scalar(255,0,0),cv::FILLED);
//     cv::circle(img,cv::Point(400,440),10,cv::Scalar(255,0,0),2);
//     cv::circle(img,cv::Point(400,440),10,cv::Scalar(255,0,0),cv::FILLED);
//     cv::circle(img,cv::Point(600,410),10,cv::Scalar(255,0,0),2);
//     cv::circle(img,cv::Point(600,410),10,cv::Scalar(255,0,0),cv::FILLED);

//     cv::imshow("cry",img);
//     cv::waitKey(0);
// }


int main()
{
    RNG r;
    VideoCapture cap(0);
    Mat img(500,500,CV_8UC3);

    while(true)
    {
        cap >> img;


        // Happy(img,r);
        int val = r.uniform(0,5);
        if(val == 0)
        {
            Happy(img,r);
        }
        else if(val == 1)
        {
            Sad(img,r);
        }
        else if(val == 2)
        {
            Smile(img,r);
        }
        else if(val == 3)
        {
            Confuse(img,r);
        }
        else
        {
            Cry(img,r);
        }
        line(img,Point(r.uniform(0,img.cols),r.uniform(0,img.rows)),Point(r.uniform(0,img.cols),r.uniform(0,img.rows)),Scalar(r.uniform(0,256),r.uniform(0,256),r.uniform(0,256)),r.uniform(2,10));
        Point pt;
        pt.x = r.uniform(0,img.cols);
        pt.y= r.uniform(0,img.rows);
        circle(img,pt,r.uniform(0,100),Scalar(r.uniform(0,256),r.uniform(0,256),r.uniform(0,256)),-1);
        imshow("img",img);
        waitKey(250);
        char wai = (char)waitKey(25);

        if(wai == 27  || wai == ('q'))
        {
            break;
        }
    }
    
    return 0;
}