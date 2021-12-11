#ifndef __SIZE_H__
#define __SIZE_H__

#include <napi.h>
#include <opencv2/opencv.hpp>

class Size : public Napi::ObjectWrap<Size> {
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  static Napi::FunctionReference constructor;

  explicit Size(const Napi::CallbackInfo &info);

  cv::Size *getInternalInstance();

private:
  Napi::Value getWidth(const Napi::CallbackInfo& info);
  void setWidth(const Napi::CallbackInfo &info, const Napi::Value &value);

  Napi::Value getHeight(const Napi::CallbackInfo& info);
  void setHeight(const Napi::CallbackInfo &info, const Napi::Value &value);

  cv::Size *_wrappedClass_;
};

#endif
