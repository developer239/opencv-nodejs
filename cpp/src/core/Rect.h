#ifndef __RECT_H__
#define __RECT_H__

#include <napi.h>
#include <opencv2/opencv.hpp>

class Rect : public Napi::ObjectWrap<Rect> {
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);

  explicit Rect(const Napi::CallbackInfo &info);

  cv::Rect *getInternalInstance();

private:
  static Napi::FunctionReference constructor;

  Napi::Value getX(const Napi::CallbackInfo& info);
  Napi::Value getY(const Napi::CallbackInfo& info);
  Napi::Value getWidth(const Napi::CallbackInfo& info);
  Napi::Value getHeight(const Napi::CallbackInfo& info);
  void rescale(const Napi::CallbackInfo& info);
  void toSquare(const Napi::CallbackInfo& info);

  cv::Rect *_wrappedClass_;
};

#endif
