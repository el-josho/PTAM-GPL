#include "VideoSource.h"

VideoSource::VideoSource() {};

void VideoSource::GetAndFillFrameBWandRGB(CVD::Image<CVD::byte> &imBW, CVD::Image<CVD::Rgb<CVD::byte> > &imRGB) {};

CVD::ImageRef VideoSource::Size() {
    return CVD::ImageRef();
};
