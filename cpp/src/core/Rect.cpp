#include "Rect.h"

Napi::FunctionReference Rect::constructor;

Napi::Object Rect::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  Napi::Function func = DefineClass(env, "Rect", {
      InstanceAccessor("x", &Rect::getX, &Rect::setX, napi_default),
      InstanceAccessor("y", &Rect::getY, &Rect::setY, napi_default),
      InstanceAccessor("width", &Rect::getWidth, &Rect::setWidth, napi_default),
      InstanceAccessor("height", &Rect::getHeight, &Rect::setHeight, napi_default),
      InstanceMethod("rescale", &Rect::rescale, napi_default),
      InstanceMethod("toSquare", &Rect::toSquare, napi_default),
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

void Rect::setX(const Napi::CallbackInfo &info, const Napi::Value &value) {
  const auto x = value.As<Napi::Number>();

  this->_wrappedClass_->x = x;
}

void Rect::setY(const Napi::CallbackInfo &info, const Napi::Value &value) {
  const auto y = value.As<Napi::Number>();

  this->_wrappedClass_->y = y;
}

void Rect::setWidth(const Napi::CallbackInfo &info, const Napi::Value &value) {
  const auto width = value.As<Napi::Number>();

  this->_wrappedClass_->width = width;
}

void Rect::setHeight(const Napi::CallbackInfo &info, const Napi::Value &value) {
  const auto height = value.As<Napi::Number>();

  this->_wrappedClass_->height = height;
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

void Rect::toSquare(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  double diff = this->_wrappedClass_->width - this->_wrappedClass_->height;

  if (diff < 0) {
    this->_wrappedClass_->width = static_cast<int>(this->_wrappedClass_->width - diff);
  } else {
    this->_wrappedClass_->height = static_cast<int>(this->_wrappedClass_->height + diff);
  }
}
