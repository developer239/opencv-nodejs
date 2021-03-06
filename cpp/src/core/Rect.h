#ifndef __RECT_H__
#define __RECT_H__

#include <napi.h>
#include <opencv2/opencv.hpp>

class Rect : public Napi::ObjectWrap<Rect> {
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  static Napi::FunctionReference constructor;

  explicit Rect(const Napi::CallbackInfo &info);

  cv::Rect *getInternalInstance();

private:
  Napi::Value getX(const Napi::CallbackInfo& info);
  void setX(const Napi::CallbackInfo &info, const Napi::Value &value);

  Napi::Value getY(const Napi::CallbackInfo& info);
  void setY(const Napi::CallbackInfo &info, const Napi::Value &value);

  Napi::Value getWidth(const Napi::CallbackInfo& info);
  void setWidth(const Napi::CallbackInfo &info, const Napi::Value &value);

  Napi::Value getHeight(const Napi::CallbackInfo& info);
  void setHeight(const Napi::CallbackInfo &info, const Napi::Value &value);

  void rescale(const Napi::CallbackInfo& info);
  void toSquare(const Napi::CallbackInfo& info);

  cv::Rect *_wrappedClass_;
};

#endif
