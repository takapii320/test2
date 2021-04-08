#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/structured_light.hpp>

int main() {
    cv::structured_light::GrayCodePattern::Params params;
    params.width = 32;
    params.height = 32;

    std::vector<cv::Mat> patternImgs;
    auto graycode = cv::structured_light::GrayCodePattern::create(params);
    graycode->generate(patternImgs);

    cv::namedWindow("Pattern", cv::WINDOW_NORMAL);
    cv::resizeWindow("Pattern", 512, 512);

    for (auto img : patternImgs) {
        cv::imshow("Pattern", img);
        cv::waitKey(500);
    }

    return 0;
}