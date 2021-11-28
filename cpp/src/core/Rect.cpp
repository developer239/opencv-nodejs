#include "Rect.h"

Napi::FunctionReference Rect::constructor;

Napi::Object Rect::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  Napi::Function func = DefineClass(env, "Rect", {
      InstanceAccessor("x", &Rect::getX, nullptr, napi_default),
      InstanceAccessor("y", &Rect::getY, nullptr, napi_default),
      InstanceAccessor("width", &Rect::getWidth, nullptr, napi_default),
      InstanceAccessor("height", &Rect::getHeight, nullptr, napi_default),
      InstanceMethod("rescale", &Rect::rescale, napi_default),
  });

  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("Rect", func);
  return exports;
}

Rect::Rect(const Napi::CallbackInfo &info) : Napi::ObjectWrap<Rect>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  int length = info.Length();

  if (length == 0) {
    this->_wrappedClass_ = new cv::Rect();
    return;
  }

  if (length != 4) {
    Napi::TypeError::New(env, "Expected 4 arguments.").ThrowAsJavaScriptException();
  }

  Napi::Number x = info[0].As<Napi::Number>();
  Napi::Number y = info[1].As<Napi::Number>();
  Napi::Number width = info[2].As<Napi::Number>();
  Napi::Number height = info[3].As<Napi::Number>();

  this->_wrappedClass_ = new cv::Rect(x, y, width, height);
}

cv::Rect *Rect::getInternalInstance() {
  return this->_wrappedClass_;
}

Napi::Value Rect::getWidth(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  int width = this->_wrappedClass_->width;
  return Napi::Number::New(env, width);
}

Napi::Value Rect::getHeight(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  int height = this->_wrappedClass_->height;
  return Napi::Number::New(env, height);
}

Napi::Value Rect::getX(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  int x = this->_wrappedClass_->x;
  return Napi::Number::New(env, x);
}

Napi::Value Rect::getY(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  int y = this->_wrappedClass_->y;
  return Napi::Number::New(env, y);
}

void Rect::rescale(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() < 1) {
    Napi::TypeError::New(env, "Argument expected.").ThrowAsJavaScriptException();
  }

  double scale = info[0].As<Napi::Number>();

  this->_wrappedClass_->width = static_cast<int>(this->_wrappedClass_->width * scale);
  this->_wrappedClass_->height = static_cast<int>(this->_wrappedClass_->height * scale);
}
