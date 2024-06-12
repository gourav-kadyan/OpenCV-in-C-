#include<iostream>
#include<opencv4/opencv2/opencv.hpp>

//imread imshow destroyWindow namedWindow destroyAllWindow imwrite

int main()
{
    // cv::Mat img = cv::Mat::zeros(cv::Size(500,500),CV_8UC3);

    // cv::circle(img,cv::Point(250,250),50,cv::Scalar(0,255,255),-1);

    // cv::imwrite("img.jpg",img);

    // cv::Mat image =  cv::imread("img.jpg");

    // cv::imshow("img",image);
    // cv::waitKey();

    //CHANGING THE INTENSITY, color , crop, scaleup etc

    cv::Mat img = cv::imread("pic.jpg");
    // cv::namedWindow("real",cv::WINDOW_NORMAL);
    // cv::imshow("real",img);
    // cv::waitKey();

    // // alpha * intensity + brightness -- use saturatecast in it

    // for(int i=0;i<img.rows;i++)
    // {
    //     for(int j=0;j<img.cols;j++)
    //     {
    //         for(int k=0;k<3;k++)
    //         {
    //             img.at<cv::Vec3b>(i,j)[k] = cv::saturate_cast<uchar>(img.at<cv::Vec3b>(i,j)[k] * 2 - 50);
    //         }
    //     }
    // }
    // cv::namedWindow("change in intensity",cv::WINDOW_NORMAL);
    // cv::imshow("change in intensity",img);
    // cv::waitKey();

    // cv::Mat cropped ;// img(cv::Range(100,100),cv::Range(img.rows-10,img.cols-20));
    // cropped = img(cv::Rect(100,100,400,400));
    // cv::namedWindow("crop",cv::WINDOW_NORMAL);
    // cv::imshow("crop",cropped);
    // cv::waitKey();

    // cv::Mat big;
    // cv::resize(img,big,cv::Size(600,800));
    // cv::namedWindow("resize",cv::WINDOW_NORMAL);
    // cv::imshow("resize",cropped);
    // cv::waitKey();

    // cv::resize(img,big,cv::Size(),2,1);
    // cv::namedWindow("scale up",cv::WINDOW_NORMAL);
    // cv::imshow("scale up",big);
    // cv::waitKey();

    // cv::Mat grey;
    // cv::cvtColor(img,grey,cv::COLOR_BGR2GRAY);
    // cv::namedWindow("grey",cv::WINDOW_NORMAL);
    // cv::imshow("grey",grey);
    // cv::waitKey();


    // //masking in images frist gray image

    cv::Mat mask(grey.size(),CV_8UC1,cv::Scalar(0));
    cv::Rect r(100,100,200,200);
    mask(r) = cv::Scalar(255);
    cv::Mat mimg;
    grey.copyTo(mimg,mask);

    cv::namedWindow("masked",cv::WINDOW_NORMAL);
    cv::imshow("masked",mimg);
    cv::waitKey();
    cv::namedWindow("masked",cv::WINDOW_NORMAL);
    cv::imshow("masked",mimg);
    cv::waitKey();


    // //affine transfomation

    // //translation

    // cv::Mat transMat = (cv::Mat_<double>(2,3) << 1,0,50,0,1,30);

    // cv::Mat trans;
    // cv::warpAffine(img,trans,transMat,img.size());
    // cv::namedWindow("trans",cv::WINDOW_NORMAL);
    // cv::imshow("trans",trans);
    // cv::waitKey();


    // //rotation
    // double angle = 90;
    // cv::Mat rotMat = (cv::getRotationMatrix2D(cv::Point(img.cols/2,img.rows/2),angle,1));
    // cv::Mat rot;
    // cv::warpAffine(img,rot,rotMat,img.size());
    // cv::namedWindow("rot",cv::WINDOW_NORMAL);
    // cv::imshow("rot",rot);
    // cv::waitKey();

    // //shearing
    
    // cv::Mat sMat = (cv::Mat_<double>(2,3) << 1,0,0.5,0,1,0.2);
    // cv::Mat skew;
    // cv::warpAffine(img,skew,sMat,img.size());
    // cv::namedWindow("skew",cv::WINDOW_NORMAL);
    // cv::imshow("skew",skew);
    // cv::waitKey();

    // //reflection

    // cv::Mat hor;
    // cv::flip(img,hor,1);

    // cv::Mat ver;
    // cv::flip(img,ver,0);

    // cv::namedWindow("hori",cv::WINDOW_NORMAL);
    // cv::imshow("hori",hor);
    // cv::waitKey();
    // cv::namedWindow("ver",cv::WINDOW_NORMAL);
    // cv::imshow("ver",ver);
    // cv::waitKey();

    cv::Mat img2 = cv::imread("pic.jpg");
    cv::resize(img2,img2,cv::Size(500,500));
    cv::namedWindow("img2",cv::WINDOW_NORMAL);
    cv::imshow("img2",img2);
    cv::waitKey();

    cv::Mat img1 = cv::imread("img2.jpg");
    cv::resize(img1,img1,cv::Size(500,500));
    cv::namedWindow("img1",cv::WINDOW_NORMAL);
    cv::imshow("img1",img1);
    cv::waitKey();

    // //Adding an image

    // cv::Mat add = img1 + img2;
    // cv::namedWindow("add",cv::WINDOW_NORMAL);
    // cv::imshow("add",add);
    // cv::waitKey();

    // //subtract an image

    // cv::Mat sub = img1 - img2;
    // cv::namedWindow("sub",cv::WINDOW_NORMAL);
    // cv::imshow("sub",sub);
    // cv::waitKey();

    // //multiply

    // cv::Mat multi = img1.mul(img2); // so that every pixel multiplied
    // cv::namedWindow("mul",cv::WINDOW_NORMAL);
    // cv::imshow("mul",multi);
    // cv::waitKey();

    // //divide 
    // cv::Mat div = img2 / img1;
    // cv::namedWindow("div",cv::WINDOW_NORMAL);
    // cv::imshow("div",div);
    // cv::waitKey();

    //overlapping an image
    // //if want to change the image behaviour then use mask

    // cv::Mat OverImg;
    // img2.copyTo(OverImg);
    // img1.copyTo(OverImg);
    // cv::namedWindow("over",cv::WINDOW_NORMAL);
    // cv::imshow("over",OverImg);
    // cv::waitKey();

    //Merging

    float alpha = 0.8;
    float beta = 1 - alpha;

    cv::Mat mer;
    cv::addWeighted(img1,alpha,img2,beta,1,mer,-1);
    cv::namedWindow("mer",cv::WINDOW_NORMAL);
    cv::imshow("mer",mer);
    cv::waitKey();

    return 0;
}