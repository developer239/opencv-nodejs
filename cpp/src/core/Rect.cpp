#include "Rect.h"

Napi::FunctionReference Rect::constructor;

Napi::Object Rect::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  Napi::Function func = DefineClass(env, "Rect", {

  });

  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("Rect", func);
  return exports;
}

Rect::Rect(const Napi::CallbackInfo &info) : Napi::ObjectWrap<Rect>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  this->_wrappedClass_ = new cv::Rect();
}

cv::Rect *Rect::getInternalInstance() {
  return this->_wrappedClass_;
}
