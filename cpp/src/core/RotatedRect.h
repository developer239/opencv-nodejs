#ifndef __ROTATEDRECT_H__
#define __ROTATEDRECT_H__

#include <napi.h>
#include <opencv2/opencv.hpp>
#include "Point.h"
#include "Size.h"

class RotatedRect : public Napi::ObjectWrap<RotatedRect> {
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  static Napi::FunctionReference constructor;

  explicit RotatedRect(const Napi::CallbackInfo &info);

  cv::RotatedRect *getInternalInstance();

private:
  Napi::Value getCenter(const Napi::CallbackInfo& info);
  Napi::Value getSize(const Napi::CallbackInfo& info);
  Napi::Value getAngle(const Napi::CallbackInfo& info);

  cv::RotatedRect *_wrappedClass_;
  Point *_wrappedClassCenter_;
  Size *_wrappedClassSize_;
};

#endif
