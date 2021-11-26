#include "Size.h"

Napi::FunctionReference Size::constructor;

Napi::Object Size::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  Napi::Function func = DefineClass(env, "Size", {

  });

  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("Size", func);
  return exports;
}

Size::Size(const Napi::CallbackInfo &info) : Napi::ObjectWrap<Size>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  this->_wrappedClass_ = new cv::Size();
}

cv::Size *Size::getInternalInstance() {
  return this->_wrappedClass_;
}
