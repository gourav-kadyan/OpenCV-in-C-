#include <opencv2/opencv.hpp>
#include <iostream>
 
int main() {
    // Load your image
    cv::Mat image = cv::imread("opencv-logo.png", cv::IMREAD_UNCHANGED);
 
    if (image.empty()) {
        std::cout << "Could not open or find the image" << std::endl;
        return -1;
    }
 
    // Define the border size
    int borderSize = 10;  // Change this value to adjust the border size
 
    // Add black border to the image
    cv::Mat imageWithBorder;
    cv::copyMakeBorder(image, imageWithBorder, borderSize, borderSize, borderSize, borderSize, cv::BORDER_CONSTANT, cv::Scalar(0, 0, 0, 255));
 
    // Create a white background image of the new size (original size + border)
    cv::Mat whiteBackground(imageWithBorder.size(), CV_8UC3, cv::Scalar(255, 255, 255));
 
    // Check if the image has an alpha channel
    if (imageWithBorder.channels() == 4) {
        std::vector<cv::Mat> channels(4);
        cv::split(imageWithBorder, channels);
 
        cv::Mat alpha = channels[3];
        cv::Mat alphaNormalized;
        alpha.convertTo(alphaNormalized, CV_32F, 1.0 / 255.0);
 
        for (int i = 0; i < 3; ++i) {
            channels[i].convertTo(channels[i], CV_32F);
            cv::Mat whiteChannel;
            cv::cvtColor(whiteBackground, whiteChannel, cv::COLOR_BGR2GRAY);
            whiteChannel.convertTo(whiteChannel, CV_32F);
 
            channels[i] = channels[i].mul(alphaNormalized) + whiteChannel.mul(1.0 - alphaNormalized);
        }
 
        cv::merge(std::vector<cv::Mat>{channels[0], channels[1], channels[2]}, whiteBackground);
        whiteBackground.convertTo(whiteBackground, CV_8UC3);
    } else {
        imageWithBorder.copyTo(whiteBackground);
    }
 
    // Display the image with white background and black border
    cv::namedWindow("whiteBackground", cv::WINDOW_NORMAL);
    cv::imshow("whiteBackground", whiteBackground);
    cv::waitKey(0);
    cv::destroyAllWindows();
 
    return 0;
}