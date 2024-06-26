#include <opencv4/opencv2/opencv.hpp>

#include <iostream>

int main() {
    cv::Mat img1 = cv::imread("leuvenA.jpg", cv::IMREAD_GRAYSCALE);
    cv::Mat img2 = cv::imread("leuvenB.jpg", cv::IMREAD_GRAYSCALE);

    cv::Ptr<cv::SIFT> sift = cv::SIFT::create();
    std::vector<cv::KeyPoint> keypoints1, keypoints2;
    cv::Mat descriptors1, descriptors2;

    sift->detectAndCompute(img1, cv::noArray(), keypoints1, descriptors1);
    sift->detectAndCompute(img2, cv::noArray(), keypoints2, descriptors2);

    cv::BFMatcher matcher(cv::NORM_L2);
    std::vector<cv::DMatch> matches;
    matcher.match(descriptors1, descriptors2, matches);

    std::sort(matches.begin(), matches.end());
    const int numGoodMatches = std::min(10, (int)matches.size());
    matches.resize(numGoodMatches);

    cv::Mat imgMatches;
    cv::drawMatches(img1, keypoints1, img2, keypoints2, matches, imgMatches, cv::Scalar::all(-1), cv::Scalar::all(-1), std::vector<char>(), cv::DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);

    cv::imshow("TOP 10 Matches", imgMatches);
    cv::imwrite("SIFT.jpg",imgMatches);
    cv::waitKey(0);

    return 0;
}
