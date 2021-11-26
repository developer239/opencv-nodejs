#ifndef __ROTATEDRECT_H__
#define __ROTATEDRECT_H__

#include <napi.h>
#include <opencv2/opencv.hpp>

class RotatedRect : public Napi::ObjectWrap<RotatedRect> {
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);

  explicit RotatedRect(const Napi::CallbackInfo &info);

  cv::RotatedRect *getInternalInstance();

private:
  static Napi::FunctionReference constructor;

  cv::RotatedRect *_wrappedClass_;
};

#endif
