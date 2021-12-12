#include "ImageShow.h"
#include "../core/Mat.h"

void ImageShow(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  // TODO: validate arguments

  std::string title = info[0].As<Napi::String>().Utf8Value();

  Napi::Object object = info[1].As<Napi::Object>();
  Mat *imageObject = Napi::ObjectWrap<Mat>::Unwrap(object);
  cv::Mat *image = imageObject->getInternalInstance();

  cv::imshow(title, *image);
}
