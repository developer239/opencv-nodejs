#ifndef __POINT_H__
#define __POINT_H__

#include <napi.h>
#include <opencv2/opencv.hpp>

class Point : public Napi::ObjectWrap<Point> {
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);

  explicit Point(const Napi::CallbackInfo &info);

  cv::Point *getInternalInstance();

private:
  static Napi::FunctionReference constructor;

  Napi::Value getX(const Napi::CallbackInfo& info);
  Napi::Value getY(const Napi::CallbackInfo& info);

  cv::Point *_wrappedClass_;
};

#endif
