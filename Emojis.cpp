#include<iostream>
#include<opencv4/opencv2/opencv.hpp>

void Happy()
{

    //Happy 
    // cv::line(img,cv::Point(400,620),cv::Point(600,620),cv::Scalar(0,0,0),2);
    cv::Mat img = cv::Mat::zeros(1000,1000,CV_8UC3);

    //structure
    cv::circle(img,cv::Point(500,500),250,cv::Scalar(0,255,255),2);
    cv::circle(img,cv::Point(500,500),250,cv::Scalar(0,255,255),cv::FILLED);

    //eyes
    cv::circle(img,cv::Point(400,370),20,cv::Scalar(0,0,0),2);
    cv::circle(img,cv::Point(400,370),20,cv::Scalar(0,0,0),cv::FILLED);
    cv::circle(img,cv::Point(600,370),20,cv::Scalar(0,0,0),2);
    cv::circle(img,cv::Point(600,370),20,cv::Scalar(0,0,0),cv::FILLED);
    cv::ellipse(img,cv::Point(500,620),cv::Size(100,50),0,0,180,cv::Scalar(0,0,255),-1);

    cv::imshow("Happy",img);
    cv::waitKey(0);
}

void Sad()
{
    cv::Mat img = cv::Mat::zeros(1000,1000,CV_8UC3);

    //structure
    cv::circle(img,cv::Point(500,500),250,cv::Scalar(0,255,255),2);
    cv::circle(img,cv::Point(500,500),250,cv::Scalar(0,255,255),cv::FILLED);

    //eyes
    cv::circle(img,cv::Point(400,370),20,cv::Scalar(0,0,0),2);
    cv::circle(img,cv::Point(400,370),20,cv::Scalar(0,0,0),cv::FILLED);
    cv::circle(img,cv::Point(600,370),20,cv::Scalar(0,0,0),2);
    cv::circle(img,cv::Point(600,370),20,cv::Scalar(0,0,0),cv::FILLED);
    cv::ellipse(img,cv::Point(500,620),cv::Size(100,50),180,0,180,cv::Scalar(0,0,0),2);
    cv::imshow("Sad",img);
    cv::waitKey(0);
}

void Confuse()
{

    cv::Mat img = cv::Mat::zeros(1000,1000,CV_8UC3);

    //structure
    cv::circle(img,cv::Point(500,500),250,cv::Scalar(0,255,255),2);
    cv::circle(img,cv::Point(500,500),250,cv::Scalar(0,255,255),cv::FILLED);

    //eyes
    cv::circle(img,cv::Point(400,370),20,cv::Scalar(0,0,0),2);
    cv::circle(img,cv::Point(400,370),20,cv::Scalar(0,0,0),cv::FILLED);
    cv::circle(img,cv::Point(600,370),20,cv::Scalar(0,0,0),2);
    cv::circle(img,cv::Point(600,370),20,cv::Scalar(0,0,0),cv::FILLED);
    cv::line(img,cv::Point(400,600),cv::Point(600,600),cv::Scalar(0,0,0),3);

    cv::imshow("confuse",img);
    cv::waitKey(0);

}

void Smile()
{

    cv::Mat img = cv::Mat::zeros(1000,1000,CV_8UC3);

    //structure
    cv::circle(img,cv::Point(500,500),250,cv::Scalar(0,255,255),2);
    cv::circle(img,cv::Point(500,500),250,cv::Scalar(0,255,255),cv::FILLED);

    //eyes
    cv::circle(img,cv::Point(400,370),20,cv::Scalar(0,0,0),2);
    cv::circle(img,cv::Point(400,370),20,cv::Scalar(0,0,0),cv::FILLED);
    cv::circle(img,cv::Point(600,370),20,cv::Scalar(0,0,0),2);
    cv::circle(img,cv::Point(600,370),20,cv::Scalar(0,0,0),cv::FILLED);
    cv::ellipse(img,cv::Point(500,620),cv::Size(100,50),0,0,180,cv::Scalar(0,0,255),4);

    cv::imshow("Smile",img);
    cv::waitKey(0);

}

void Cry()
{
    cv::Mat img = cv::Mat::zeros(1000,1000,CV_8UC3);

    //structure
    cv::circle(img,cv::Point(500,500),250,cv::Scalar(0,255,255),2);
    cv::circle(img,cv::Point(500,500),250,cv::Scalar(0,255,255),cv::FILLED);

    //eyes
    cv::circle(img,cv::Point(400,370),20,cv::Scalar(0,0,0),2);
    cv::circle(img,cv::Point(400,370),20,cv::Scalar(0,0,0),cv::FILLED);
    cv::circle(img,cv::Point(600,370),20,cv::Scalar(0,0,0),2);
    cv::circle(img,cv::Point(600,370),20,cv::Scalar(0,0,0),cv::FILLED);
    cv::ellipse(img,cv::Point(500,620),cv::Size(100,50),0,0,360,cv::Scalar(0,0,255),-1);
    cv::circle(img,cv::Point(400,410),10,cv::Scalar(255,0,0),2);
    cv::circle(img,cv::Point(400,410),10,cv::Scalar(255,0,0),cv::FILLED);
    cv::circle(img,cv::Point(600,440),10,cv::Scalar(255,0,0),2);
    cv::circle(img,cv::Point(600,440),10,cv::Scalar(255,0,0),cv::FILLED);
    cv::circle(img,cv::Point(400,440),10,cv::Scalar(255,0,0),2);
    cv::circle(img,cv::Point(400,440),10,cv::Scalar(255,0,0),cv::FILLED);
    cv::circle(img,cv::Point(600,410),10,cv::Scalar(255,0,0),2);
    cv::circle(img,cv::Point(600,410),10,cv::Scalar(255,0,0),cv::FILLED);

    cv::imshow("cry",img);
    cv::waitKey(0);
}

int main()
{

    Happy();
    Sad();
    Confuse();
    Smile();
    Cry();


    return 0;
}