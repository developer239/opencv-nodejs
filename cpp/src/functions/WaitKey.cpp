#include "ImageShow.h"

void WaitKey(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  if (info[0].As<Napi::Value>().IsNumber()) {
    cv::waitKey(info[0].As<Napi::Number>());
  } else {
    cv::waitKey(0);
  }
}
