#include "ImageShow.h"
#include <iostream>

void ImageShow(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  // TODO: validate arguments

  std::string title = info[0].As<Napi::String>().Utf8Value();

  cv::imshow(title, cv::Mat(100,100, CV_8UC3, 255));

  std::cout << "show";
}
