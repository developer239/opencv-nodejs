#ifndef __MAT_H__
#define __MAT_H__

#include <napi.h>
#include <opencv2/opencv.hpp>

class Mat : public Napi::ObjectWrap<Mat> {
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  static Napi::FunctionReference constructor;

  explicit Mat(const Napi::CallbackInfo &info);

  void bindMat(cv::Mat *matrix);

  cv::Mat *getInternalInstance();
private:
  cv::Mat *_wrappedClass_;

  Napi::Value getCols(const Napi::CallbackInfo& info);
  Napi::Value getRows(const Napi::CallbackInfo& info);
  Napi::Value type(const Napi::CallbackInfo& info);
  Napi::Value at(const Napi::CallbackInfo& info);
};

#endif
