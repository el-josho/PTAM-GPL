
#include <iostream>

#include <cvd/image.h>
#include <cvd/byte.h>
#include <cvd/rgb.h>
#include <cvd/utility.h>

#include <opencv2/opencv.hpp>

#include "VideoSource.h"

class VideoOpenCVSource {
 public:
  VideoOpenCVSource();
  ~VideoOpenCVSource();
  void GetAndFillFrameBWandRGB(CVD::Image<CVD::byte>& imBW,
                               CVD::Image<CVD::Rgb<CVD::byte> >& imRGB);
  CVD::ImageRef Size();

 private:
  void* mptr;
  CVD::ImageRef mirSize;
  cv::VideoCapture capture;
};
