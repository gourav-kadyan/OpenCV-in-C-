// #include "opencv2/highgui.hpp"
// #include "opencv2/imgproc.hpp"
// #include<iostream>
 
// using namespace cv;
// using namespace std;
 
// int main() {
// // load source image and grayscale template
// //  samples::addSamplesDataSearchSubDirectory("doc/tutorials/imgproc/generalized_hough_ballard_guil");
//  Mat image = imread(samples::findFile("img.jpg"));
//  Mat templ = imread(samples::findFile("img2.jpg"), IMREAD_GRAYSCALE);
 
// // create grayscale image
//  Mat grayImage;
//  cvtColor(image, grayImage, COLOR_RGB2GRAY);
 
// // create variable for location, scale and rotation of detected templates
//  vector<Vec4f> positionBallard, positionGuil;
 
// // template width and height
//  int w = templ.cols;
//  int h = templ.rows;
 
 
// // create ballard and set options
//  Ptr<GeneralizedHoughBallard> ballard = createGeneralizedHoughBallard();
//  ballard->setMinDist(10);
//  ballard->setLevels(360);
//  ballard->setDp(2);
//  ballard->setMaxBufferSize(1000);
//  ballard->setVotesThreshold(40);
 
//  ballard->setCannyLowThresh(30);
//  ballard->setCannyHighThresh(110);
//  ballard->setTemplate(templ);
 
 
// // create guil and set options
//  Ptr<GeneralizedHoughGuil> guil = createGeneralizedHoughGuil();
//  guil->setMinDist(10);
//  guil->setLevels(360);
//  guil->setDp(3);
//  guil->setMaxBufferSize(1000);
 
//  guil->setMinAngle(0);
//  guil->setMaxAngle(360);
//  guil->setAngleStep(1);
//  guil->setAngleThresh(1500);
 
//  guil->setMinScale(0.5);
//  guil->setMaxScale(2.0);
//  guil->setScaleStep(0.05);
//  guil->setScaleThresh(50);
 
//  guil->setPosThresh(10);
 
//  guil->setCannyLowThresh(30);
//  guil->setCannyHighThresh(110);
 
//  guil->setTemplate(templ);
 
 
// // execute ballard detection
//  ballard->detect(grayImage, positionBallard);
// // execute guil detection
//  guil->detect(grayImage, positionGuil);
 
 
// // draw ballard
//  for (vector<Vec4f>::iterator iter = positionBallard.begin(); iter != positionBallard.end(); ++iter) {
//  RotatedRect rRect = RotatedRect(Point2f((*iter)[0], (*iter)[1]),
//  Size2f(w * (*iter)[2], h * (*iter)[2]),
//  (*iter)[3]);
//  Point2f vertices[4];
//  rRect.points(vertices);
//  for (int i = 0; i < 4; i++)
//  line(image, vertices[i], vertices[(i + 1) % 4], Scalar(255, 0, 0), 6);
//  }
 
// // draw guil
//  for (vector<Vec4f>::iterator iter = positionGuil.begin(); iter != positionGuil.end(); ++iter) {
//  RotatedRect rRect = RotatedRect(Point2f((*iter)[0], (*iter)[1]),
//  Size2f(w * (*iter)[2], h * (*iter)[2]),
//  (*iter)[3]);
//  Point2f vertices[4];
//  rRect.points(vertices);
//  for (int i = 0; i < 4; i++)
//  line(image, vertices[i], vertices[(i + 1) % 4], Scalar(0, 255, 0), 2);
//  }
 
//  imshow("result_img", image);
//  waitKey();
 
//  return EXIT_SUCCESS;
// }


#include <opencv2/opencv.hpp>
#include <iostream>

// int main() {
//     // Load the image
//     cv::Mat src = cv::imread("pic.jpg");
//     if (src.empty()) {
//         std::cerr << "Error loading image" << std::endl;
//         return -1;
//     }

//     // Convert to grayscale
//     cv::Mat gray;
//     cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);

//     // Apply Gaussian blur
//     cv::GaussianBlur(gray, gray, cv::Size(9, 9), 2, 2);

//     // Detect circles using Hough Transform
//     std::vector<cv::Vec3f> circles;
//     cv::HoughCircles(gray, circles, cv::HOUGH_GRADIENT, 1, gray.rows/8, 200, 100, 0, 0);

//     // Draw the circles on the original image
//     for (size_t i = 0; i < circles.size(); i++) {
//         cv::Vec3f c = circles[i];
//         cv::Point center = cv::Point(cvRound(c[0]), cvRound(c[1]));
//         int radius = cvRound(c[2]);
//         cv::circle(src, center, radius, cv::Scalar(0,255,0), 3, cv::LINE_AA);
//         cv::circle(src, center, 2, cv::Scalar(0,0,255), 3, cv::LINE_AA);
//     }

//     // Display the result
//     cv::namedWindow("Detected Circles", cv::WINDOW_NORMAL);
//     cv::imshow("Detected Circles", src);
//     cv::waitKey(0);

//     return 0;
// }

// #include "opencv2/highgui.hpp"
// #include "opencv2/imgproc.hpp"
 
using namespace cv;
using namespace std;
 
int main() {
// load source image and grayscale template
//  samples::addSamplesDataSearchSubDirectory("doc/tutorials/imgproc/generalized_hough_ballard_guil");
 Mat image = imread("messi5.jpg");
 Mat templ = imread("messi5.jpg", IMREAD_GRAYSCALE);
 
// create grayscale image
 Mat grayImage;
 cvtColor(image, grayImage, COLOR_RGB2GRAY);
 
// create variable for location, scale and rotation of detected templates
 vector<Vec4f> positionBallard, positionGuil;
 
// template width and height
 int w = templ.cols;
 int h = templ.rows;
 
 
// create ballard and set options
 Ptr<GeneralizedHoughBallard> ballard = createGeneralizedHoughBallard();
 ballard->setMinDist(10);
 ballard->setLevels(360);
 ballard->setDp(2);
 ballard->setMaxBufferSize(1000);
 ballard->setVotesThreshold(40);
 
 ballard->setCannyLowThresh(30);
 ballard->setCannyHighThresh(110);
 ballard->setTemplate(templ);
 
 
// create guil and set options
 Ptr<GeneralizedHoughGuil> guil = createGeneralizedHoughGuil();
 guil->setMinDist(10);
 guil->setLevels(360);
 guil->setDp(3);
 guil->setMaxBufferSize(1000);
 
 guil->setMinAngle(0);
 guil->setMaxAngle(360);
 guil->setAngleStep(1);
 guil->setAngleThresh(1500);
 
 guil->setMinScale(0.5);
 guil->setMaxScale(2.0);
 guil->setScaleStep(0.05);
 guil->setScaleThresh(50);
 
 guil->setPosThresh(10);
 
 guil->setCannyLowThresh(30);
 guil->setCannyHighThresh(110);
 
 guil->setTemplate(templ);
 
 
// execute ballard detection
 ballard->detect(grayImage, positionBallard);
// execute guil detection
 guil->detect(grayImage, positionGuil);
 
 
// draw ballard
 for (vector<Vec4f>::iterator iter = positionBallard.begin(); iter != positionBallard.end(); ++iter) {
 RotatedRect rRect = RotatedRect(Point2f((*iter)[0], (*iter)[1]),
 Size2f(w * (*iter)[2], h * (*iter)[2]),
 (*iter)[3]);
 Point2f vertices[4];
 rRect.points(vertices);
 for (int i = 0; i < 4; i++)
 line(image, vertices[i], vertices[(i + 1) % 4], Scalar(255, 0, 0), 6);
 }
 
// draw guil
 for (vector<Vec4f>::iterator iter = positionGuil.begin(); iter != positionGuil.end(); ++iter) {
 RotatedRect rRect = RotatedRect(Point2f((*iter)[0], (*iter)[1]),
 Size2f(w * (*iter)[2], h * (*iter)[2]),
 (*iter)[3]);
 Point2f vertices[4];
 rRect.points(vertices);
 for (int i = 0; i < 4; i++)
 line(image, vertices[i], vertices[(i + 1) % 4], Scalar(0, 255, 0), 2);
 }
 
 imshow("result_img", image);
 waitKey();
 
 return EXIT_SUCCESS;
}