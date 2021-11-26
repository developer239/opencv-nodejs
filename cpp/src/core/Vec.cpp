#include "Vec.h"

Napi::FunctionReference Vec::constructor;

Napi::Object Vec::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  Napi::Function func = DefineClass(env, "Vec", {

  });

  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("Vec", func);
  return exports;
}

Vec::Vec(const Napi::CallbackInfo &info) : Napi::ObjectWrap<Vec>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  this->_wrappedClass_ = new cv::Vec2d(10, 20);
}
