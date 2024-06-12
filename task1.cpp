// #include <opencv2/opencv.hpp>
// #include <iostream>

// using namespace cv;
// using namespace std;
// double area;
// double perimeter;
// size_t c;
// Moments processImage(const string &imagePath)
// {
//     // Load the image
//     Mat image = imread(imagePath);
//     if (image.empty())
//     {
//         cerr << "Error: Could not load image!" << endl;
//         return;
//     }

//     // Convert to grayscale
//     Mat gray;
//     cvtColor(image, gray, COLOR_BGR2GRAY);

//     // Noise reduction using Gaussian Blur
//     Mat blurred;
//     GaussianBlur(gray, blurred, Size(5, 5), 0);

//     // Thresholding
//     Mat thresholded;
//     threshold(blurred, thresholded, 128, 255, THRESH_BINARY);

//     // Find contours
//     vector<vector<Point>> contours;
//     vector<Vec4i> hierarchy;
//     findContours(thresholded, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);

//     // Analyze each contour
//     Moments moments;
//     for (size_t i = 0; i < contours.size(); i++)
//     {
//         // Convex hull
//         vector<Point> hull;
//         convexHull(contours[i], hull);

//         // Minimum bounding rectangle
//         Rect minBoundingRect = boundingRect(contours[i]);

//         // Rotated rectangle
//         RotatedRect rotatedRect = minAreaRect(contours[i]);

//         // Minimum enclosing circle
//         Point2f center;
//         float radius;
//         minEnclosingCircle(contours[i], center, radius);

//         // Fit ellipse
//         if (contours[i].size() >= 5)
//         {
//             RotatedRect ellipseFit = fitEllipse(contours[i]);
//             ellipse(image, ellipseFit, Scalar(0, 255, 0), 2);
//         }

//         // Calculate image moments
//         moments = cv::moments(contours[i]);

//         // Contour area
//         area = contourArea(contours[i]);

//         // Contour perimeter
//         perimeter = arcLength(contours[i], true);

//         // Draw results on the image
//         drawContours(image, contours, (int)i, Scalar(255, 0, 0), 2);
//         polylines(image, hull, true, Scalar(0, 255, 0), 2);
//         rectangle(image, minBoundingRect, Scalar(0, 0, 255), 2);
//         Point2f rect_points[4];
//         rotatedRect.points(rect_points);
//         for (int j = 0; j < 4; j++)
//             line(image, rect_points[j], rect_points[(j + 1) % 4], Scalar(255, 255, 0), 2);
//         circle(image, center, (int)radius, Scalar(255, 0, 255), 2);

//         // Display moments, area, and perimeter

//         c = i;
//     }

//     // Display the result
//     imwrite("219492-4a.jpg", image);
//     // waitKey(0);
//     return moments;
// }

// int main()
// {
//     string imagePath = "opencv-logo.png"; // Replace with your image path
//     Momments moments =  processImage(imagePath);

//     cout << "Contour #" << c + 1 << ":" << endl;
//     cout << "  Area: " << area << endl;
//     cout << "  Perimeter: " << perimeter << endl;
//     cout << "  Moments: [m00: " << moments.m00 << ", m10: " << moments.m10
//              << ", m01: " << moments.m01 << ", mu20: " << moments.mu20
//              << ", mu11: " << moments.mu11 << ", mu02: " << moments.mu02 << "]" << endl;
//     return 0;
// }

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

double area;
double perimeter;
size_t c;

Moments processImage(const string &imagePath)
{

    Mat image = imread(imagePath);
    if (image.empty())
    {
        cerr << "Error: Could not load image!" << endl;
        return Moments();
    }

    Mat gray;
    cvtColor(image, gray, COLOR_BGR2GRAY);

    Mat blurred;
    GaussianBlur(gray, blurred, Size(5, 5), 0);

    Mat thresholded;
    threshold(blurred, thresholded, 0, 255, THRESH_BINARY);

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(thresholded, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);

    Moments moments;
    for (size_t i = 0; i < contours.size(); i++)
    {
        vector<Point> hull;
        convexHull(contours[i], hull);

        Rect minBoundingRect = boundingRect(contours[i]);

        RotatedRect rotatedRect = minAreaRect(contours[i]);

        Point2f center;
        float radius;
        minEnclosingCircle(contours[i], center, radius);

        if (contours[i].size() >= 5)
        {
            RotatedRect ellipseFit = fitEllipse(contours[i]);
            ellipse(image, ellipseFit, Scalar(0, 255, 0), 2);
        }

        moments = cv::moments(contours[i]);

        area = contourArea(contours[i]);

        perimeter = arcLength(contours[i], true);
        drawContours(image, contours, int(i), Scalar(255, 0, 0), 2);
        polylines(image, hull, true, Scalar(0, 255, 0), 2);
        rectangle(image, minBoundingRect, Scalar(0, 0, 255), 2);
        Point2f rect_points[4];
        rotatedRect.points(rect_points);
        for (int j = 0; j < 4; j++)
            line(image, rect_points[j], rect_points[(j + 1) % 4], Scalar(255, 255, 0), 2);
        circle(image, center, (int)radius, Scalar(255, 0, 255), 2);
        c = i;
        cout << "Contour #" << c + 1 << ":" << endl;
        cout << "  Area: " << area << endl;
        cout << "  Perimeter: " << perimeter << endl;
        cout << "  Moments: [m00: " << moments.m00 << ", m10: " << moments.m10
             << ", m01: " << moments.m01 << ", mu20: " << moments.mu20
             << ", mu11: " << moments.mu11 << ", mu02: " << moments.mu02 << "]" << endl;
    }

    imwrite("219492-4a.jpg", image);

    return moments;
}

int main()
{

    Moments moments = processImage("opencv-logo.png");

    

    return 0;
}
