#ifndef __POINT_H__
#define __POINT_H__

#include <napi.h>
#include <opencv2/opencv.hpp>

class Point : public Napi::ObjectWrap<Point> {
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  static Napi::FunctionReference constructor;

  explicit Point(const Napi::CallbackInfo &info);

  cv::Point *getInternalInstance();
private:
  Napi::Value getX(const Napi::CallbackInfo& info);
  Napi::Value getY(const Napi::CallbackInfo& info);
  void setX(const Napi::CallbackInfo &info, const Napi::Value &value);
  void setY(const Napi::CallbackInfo &info, const Napi::Value &value);
  Napi::Value add(const Napi::CallbackInfo& info);
  Napi::Value subtract(const Napi::CallbackInfo& info);

  cv::Point *_wrappedClass_;
};

#endif
