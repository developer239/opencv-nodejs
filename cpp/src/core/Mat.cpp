#include "Mat.h"

Napi::FunctionReference Mat::constructor;

Napi::Object Mat::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  Napi::Function func = DefineClass(env, "Mat", {
      InstanceAccessor("cols", &Mat::getCols, nullptr),
      InstanceAccessor("rows", &Mat::getRows, nullptr),
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

void Mat::bindMat(cv::Mat *matrix) {
  this->_wrappedClass_ = matrix;
}

Napi::Value Mat::getCols(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  int cols = this->_wrappedClass_->cols;
  return Napi::Number::New(env, cols);
}

Napi::Value Mat::getRows(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  int cols = this->_wrappedClass_->cols;
  return Napi::Number::New(env, cols);
}
