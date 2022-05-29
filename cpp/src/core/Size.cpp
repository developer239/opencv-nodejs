#include "Size.h"

Napi::FunctionReference Size::constructor;

Napi::Object Size::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  Napi::Function func = DefineClass(env, "Size", {
      InstanceAccessor("width", &Size::getWidth, &Size::setWidth, napi_default),
      InstanceAccessor("height", &Size::getHeight, &Size::setHeight, napi_default),
  });

  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("Size", func);
  return exports;
}

Size::Size(const Napi::CallbackInfo &info) : Napi::ObjectWrap<Size>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  int length = info.Length();

  if (length == 0) {
    // 💣
    this->_wrappedClass_ = new cv::Size();
    return;
  }

  if (length != 2) {
    Napi::TypeError::New(env, "Expected 2 arguments.").ThrowAsJavaScriptException();
  }

  Napi::Number width = info[0].As<Napi::Number>();
  Napi::Number height = info[1].As<Napi::Number>();

  // 💣
  this->_wrappedClass_ = new cv::Size(width, height);
}

cv::Size *Size::getInternalInstance() {
  return this->_wrappedClass_;
}

Napi::Value Size::getWidth(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  int width = this->_wrappedClass_->width;
  return Napi::Number::New(env, width);
}

Napi::Value Size::getHeight(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  int height = this->_wrappedClass_->height;
  return Napi::Number::New(env, height);
}

void Size::setWidth(const Napi::CallbackInfo &info, const Napi::Value &value) {
  const auto width = value.As<Napi::Number>();

  this->_wrappedClass_->width = width;
}

void Size::setHeight(const Napi::CallbackInfo &info, const Napi::Value &value) {
  const auto height = value.As<Napi::Number>();

  this->_wrappedClass_->height = height;
}
