#ifndef __VEC_H__
#define __VEC_H__

#include <napi.h>
#include <opencv2/opencv.hpp>

class Vec : public Napi::ObjectWrap<Vec> {
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);

  explicit Vec(const Napi::CallbackInfo &info);

private:
  static Napi::FunctionReference constructor;

  cv::Vec2d *_wrappedClass_;
};

#endif
