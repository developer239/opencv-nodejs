#include "Mat.h"

Napi::FunctionReference Mat::constructor;

Napi::Object Mat::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  Napi::Function func = DefineClass(env, "Mat", {
  });

  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("Mat", func);
  return exports;
}

Mat::Mat(const Napi::CallbackInfo &info) : Napi::ObjectWrap<Mat>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  this->_wrappedClass_ = new cv::Mat();
  return;
}

cv::Mat *Mat::getInternalInstance() {
  return this->_wrappedClass_;
}
