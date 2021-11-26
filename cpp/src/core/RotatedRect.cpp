#include "RotatedRect.h"

Napi::FunctionReference RotatedRect::constructor;

Napi::Object RotatedRect::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  Napi::Function func = DefineClass(env, "RotatedRect", {

  });

  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("RotatedRect", func);
  return exports;
}

RotatedRect::RotatedRect(const Napi::CallbackInfo &info) : Napi::ObjectWrap<RotatedRect>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  this->_wrappedClass_ = new cv::RotatedRect();
}

cv::RotatedRect *RotatedRect::getInternalInstance() {
  return this->_wrappedClass_;
}
