#ifndef __SIZE_H__
#define __SIZE_H__

#include <napi.h>
#include <opencv2/opencv.hpp>

class Size : public Napi::ObjectWrap<Size> {
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);

  explicit Size(const Napi::CallbackInfo &info);

  cv::Size *getInternalInstance();

private:
  static Napi::FunctionReference constructor;

  cv::Size *_wrappedClass_;
};

#endif
