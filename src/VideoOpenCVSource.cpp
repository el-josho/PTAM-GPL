#include <VideoOpenCVSource.hpp>

VideoOpenCVSource::VideoOpenCVSource() : mirSize(), capture(0) {
  if (!capture.isOpened())
    std::cerr << "Failed to open video capture!" << std::endl;

  // get one frame to determine image size
  cv::Mat initialFrame;
  capture.read(initialFrame);
  mirSize = CVD::ImageRef(initialFrame.cols, initialFrame.rows);
};

VideoOpenCVSource::~VideoOpenCVSource() {
}

void VideoOpenCVSource::GetAndFillFrameBWandRGB(
    CVD::Image<CVD::byte>& imBW,
    CVD::Image<CVD::Rgb<CVD::byte> >& imRGB) {
  cv::Mat rgbFrame, grayFrame;

  // fetch camera frame and resize
  capture.read(rgbFrame);
  mirSize = CVD::ImageRef(rgbFrame.cols, rgbFrame.rows);
  // cv::resize(rgbFrame, rgbFrame, cv::Size(VIDEO_WIDTH, VIDEO_HEIGHT));

  // extract rgb frame and store to rgb image parameter
  cv::cvtColor(rgbFrame, rgbFrame, CV_BGR2RGB);
  CVD::BasicImage<CVD::Rgb<CVD::byte> > cvdRgbFrame(
      (CVD::Rgb<CVD::byte>*)rgbFrame.data,
      CVD::ImageRef(rgbFrame.cols, rgbFrame.rows));
  imRGB.copy_from(cvdRgbFrame);

  // extract gray frame and store to gray image parameter
  cv::cvtColor(rgbFrame, grayFrame, CV_RGB2GRAY);
  CVD::BasicImage<CVD::byte> cvdGrayFrame(
      (CVD::byte*)grayFrame.data,
      CVD::ImageRef(grayFrame.cols, grayFrame.rows));
  imBW.copy_from(cvdGrayFrame);
};

CVD::ImageRef VideoOpenCVSource::Size() {
  return mirSize;
}
