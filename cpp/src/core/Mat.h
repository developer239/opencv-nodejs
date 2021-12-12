#ifndef __MAT_H__
#define __MAT_H__

#include <napi.h>
#include <opencv2/opencv.hpp>

class Mat : public Napi::ObjectWrap<Mat> {
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  static Napi::FunctionReference constructor;

  explicit Mat(const Napi::CallbackInfo &info);

  cv::Mat *getInternalInstance();
private:
  cv::Mat *_wrappedClass_;
};

#endif
