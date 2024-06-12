// #include<iostream>
// #include<opencv4/opencv2/opencv.hpp>

// using namespace std;
// using namespace cv;

// void Day1()
// {
//     //edge detection 
//     Mat img = imread("building.jpg");
//     imshow("real img",img);
//     waitKey(0);

//     //1 -> Sobel edge detection
//     Mat sob;
//     Mat sob_x,sob_y,sobker;
//     Sobel(img,sob,-1,0,1);
//     imshow("sobel y wala img",sob);
//     convertScaleAbs(sob,sob_y);
//     Sobel(img,sob,-1,1,0);
//     imshow("soble x wala",sob);
//     convertScaleAbs(sob,sob_x);
//     Sobel(img,sob,-1,1,1);
//     imshow("sobel xy wala",sob);
//     addWeighted(sob_x,0.5,sob_y,0.5,1,sobker);
//     imshow("sobel edge detection ",sobker);
//     waitKey(0);


//     //2 -> prewitt edge detection
//     Mat wittx,witty;
//     Mat prewitt_x_kernel = (Mat_<float>(3,3) << -1,0,1,-1,0,1,-1,0,1);
//     Mat prewitt_y_kernel = (Mat_<float>(3,3) << -1,-1,-1,0,0,0,1,1,1);
//     Mat pre_x,pre_y;
//     filter2D(img,pre_x,-1,prewitt_x_kernel);
//     imshow("prewitt x",pre_x);
//     filter2D(img,pre_y,-1,prewitt_y_kernel);
//     imshow("prewitt y",pre_y);
    
//     convertScaleAbs(pre_x,wittx);
//     convertScaleAbs(pre_y,witty);
//     Mat prewitt;
//     addWeighted(wittx,0.5,witty,0.5,1,prewitt);
//     imshow("prewitt edge detection",prewitt);
//     waitKey(0);

//     //3-> laplace (sensitive to noise)
//     Mat lappy;
//     Laplacian(img,lappy,-1);
//     imshow("laplace",lappy);
//     waitKey(0);

//     //4 - canny (robust and slow)
//     Mat cann;
//     Canny(img,cann,50,255);
//     imshow("Canny",cann);
//     waitKey(0);
// }



// int main()
// {
//     // Day1();

//     return (EXIT_SUCCESS);
// }


// ****************HOUGH LINE TRANSFORMATION******************************
// #include <opencv2/opencv.hpp>
// #include <iostream>
// using namespace cv;
// using namespace std;
// int main() {
//     Mat src = imread("building.jpg", IMREAD_GRAYSCALE);
//     if (src.empty()) {
//         cerr << "Error: Could not load image!" << endl;
//         return -1;
//     }
//     Mat edges;
//     Canny(src, edges, 50, 200, 3);
//     vector<Vec2f> lines;
//     HoughLines(edges, lines, 1, CV_PI / 180, 150);
//     Mat result;
//     cvtColor(edges, result, COLOR_GRAY2BGR);
//     for (size_t i = 0; i < lines.size(); i++) {
//         float rho = lines[i][0], theta = lines[i][1];
//         Point pt1, pt2;
//         double a = cos(theta), b = sin(theta);
//         double x0 = a * rho, y0 = b * rho;
//         pt1.x = cvRound(x0 + 1000 * (-b));
//         pt1.y = cvRound(y0 + 1000 * (a));
//         pt2.x = cvRound(x0 - 1000 * (-b));
//         pt2.y = cvRound(y0 - 1000 * (a));
//         line(result, pt1, pt2, Scalar(0, 0, 255), 2, LINE_AA);
//     }
//     imshow("Detected Lines", result);
//     waitKey(0);
//     return 0;
// }



//**********************HOUGH CIRCLE TRANSFORMATION********************
// #include <opencv2/opencv.hpp>
// #include <iostream>
// using namespace cv;
// using namespace std;
// int main() {
//     Mat src = imread("smarties.png", IMREAD_GRAYSCALE);
//     if (src.empty()) {
//         cerr << "Error: Could not load image!" << endl;
//         return -1;
//     }
//     Mat blurred;
//     GaussianBlur(src, blurred, Size(9, 9), 2, 2);
//     vector<Vec3f> circles;
//     HoughCircles(blurred, circles, HOUGH_GRADIENT, 1, blurred.rows / 8, 200, 50, 0, 0);
//     Mat result;
//     cvtColor(src, result, COLOR_GRAY2BGR);
//     for (size_t i = 0; i < circles.size(); i++) {
//         Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
//         int radius = cvRound(circles[i][2]);
//         circle(result, center, radius, Scalar(0, 255, 0), 2, LINE_AA);
//         circle(result, center, 3, Scalar(0, 0, 255), 3, LINE_AA);
//     }
//     imshow("Detected Circles", result);
//     waitKey(0);
//     return 0;
// }


//*********************GENERALISED GUIL HOUGH DETECTION*************************
// #include <opencv2/opencv.hpp>
// #include <iostream>
// using namespace cv;
// using namespace std;
// int main() {
//     Mat templateImage = imread("pic1.png", IMREAD_GRAYSCALE);
//     Mat targetImage = imread("templ.png", IMREAD_GRAYSCALE);
//     if (templateImage.empty() || targetImage.empty()) {
//         cerr << "Error: Could not load images!" << endl;
//         return -1;
//     }
//     Ptr<GeneralizedHoughBallard> ght = createGeneralizedHoughBallard();
//     ght->setTemplate(templateImage);
//     vector<Vec4f> positions;
//     ght->detect(targetImage, positions);
//     Mat result;
//     cvtColor(targetImage, result, COLOR_GRAY2BGR);
//     for (size_t i = 0; i < positions.size(); i++) {
//         Point center(cvRound(positions[i][0]), cvRound(positions[i][1]));
//         int radius = cvRound(positions[i][2]);
//         circle(result, center, radius, Scalar(0, 255, 0), 2, LINE_AA);
//     }
//     imshow("Detected Objects", result);
//     imwrite("result.jpg",result);
//     waitKey(0);
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <opencv2/opencv.hpp>
 
// using namespace cv;
// using namespace std;
 
// int main()
// {
//     Mat sample = imread("pic1.png");
//     Mat templ = imread("templ.png", IMREAD_GRAYSCALE);
 
//     int minDist = 160;
//     int levels = 250;
//     int dp = 1;
//     int bufferSize = 1500;
//     int votesThreshold = 40;
//     int cannyLowThresh = 10;
//     int cannyHighThresh = 150;
 
//     Mat grayImage;
//     cvtColor(sample, grayImage, COLOR_BGR2GRAY);
 
//     int w = templ.cols;
//     int h = templ.rows;
 
//     Mat displayImage = sample.clone();
 
//     Ptr<GeneralizedHoughBallard> ballard = createGeneralizedHoughBallard();
//     ballard->setMinDist(minDist);
//     ballard->setLevels(levels);
//     ballard->setDp(dp);
//     ballard->setMaxBufferSize(bufferSize);
//     ballard->setVotesThreshold(votesThreshold);
//     ballard->setCannyLowThresh(cannyLowThresh);
//     ballard->setCannyHighThresh(cannyHighThresh);
//     ballard->setTemplate(templ);
 
//     vector<Vec4f> positionBallard;
//     ballard->detect(grayImage, positionBallard);
 
//     for (const Vec4f &pos : positionBallard)
//     {
//         RotatedRect rRect = RotatedRect(Point2f(pos[0], pos[1]), Size2f(w * pos[2], h * pos[2]), pos[3]);
//         Point2f vertices[4];
//         rRect.points(vertices);
//         for (int i = 0; i < 4; i++)
//         {
//             line(displayImage, vertices[i], vertices[(i + 1) % 4], Scalar(0, 0, 255), 2);
//         }
//     }
 
//     resize(sample, sample, Size(800, 500));
//     resize(templ, templ, Size(400, 500));
//     resize(displayImage, displayImage, Size(800, 500));
//     imshow("Sample", sample);
//     imshow("Template", templ);
//     imshow("Object Detection", displayImage);
//     waitKey(0);
 
//     return 0;
// }

