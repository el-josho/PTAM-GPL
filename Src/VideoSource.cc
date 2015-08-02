#include "VideoSource.h"

VideoSource::VideoSource()
: mirSize(VIDEO_WIDTH, VIDEO_HEIGHT)
, capture(0) {
    if (!capture.isOpened())
        std::cerr << "Failed to open video capture!" << std::endl;
};

VideoSource::~VideoSource() {}

void VideoSource::GetAndFillFrameBWandRGB(
  CVD::Image<CVD::byte> &imBW
, CVD::Image<CVD::Rgb<CVD::byte> > &imRGB
) {
    cv::Mat rgbFrame, grayFrame;

    // fetch camera frame and resize
    capture.read(rgbFrame);
    cv::resize(rgbFrame, rgbFrame, cv::Size(VIDEO_WIDTH, VIDEO_HEIGHT));

    // extract rgb frame and store to rgb image parameter
    cv::cvtColor(rgbFrame, rgbFrame, CV_BGR2RGB);
    CVD::BasicImage<CVD::Rgb<CVD::byte> > cvdRgbFrame(
        (CVD::Rgb<CVD::byte>*) rgbFrame.data,
        CVD::ImageRef(rgbFrame.cols, rgbFrame.rows)
        );
    imRGB.copy_from(cvdRgbFrame);

    // extract gray frame and store to gray image parameter
    cv::cvtColor(rgbFrame, grayFrame, CV_RGB2GRAY);
    CVD::BasicImage<CVD::byte> cvdGrayFrame(
        (CVD::byte*) grayFrame.data,
        CVD::ImageRef(grayFrame.cols, grayFrame.rows)
        );
    imBW.copy_from(cvdGrayFrame);
};

CVD::ImageRef VideoSource::Size() {
    return mirSize;
}
