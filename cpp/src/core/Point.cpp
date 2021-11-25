#include "Point.h"

Napi::FunctionReference Point::constructor;

Napi::Object Point::Init(Napi::Env env, Napi::Object exports) {
  // TODO: this this necessary?
  Napi::HandleScope scope(env);

  Napi::Function func = DefineClass(env, "Point", {
      InstanceMethod("getX", &Point::getX),
      InstanceMethod("getY", &Point::getY),
  });

  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("Point", func);
  return exports;
}

Point::Point(const Napi::CallbackInfo &info) : Napi::ObjectWrap<Point>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  int length = info.Length();

  if (length == 0) {
    Napi::TypeError::New(env, "Arguments expected.").ThrowAsJavaScriptException();
  }

  if (length == 1) {
    Napi::Object object_parent = info[0].As<Napi::Object>();

    Point *example_parent = Napi::ObjectWrap<Point>::Unwrap(object_parent);
    cv::Point *parent_actual_class_instance = example_parent->getInternalInstance();

    // TODO: this only handles 2D points
    this->_wrappedClass_ = new cv::Point(parent_actual_class_instance->x, parent_actual_class_instance->y);
    return;
  }

  if (length == 2) {
    Napi::Number x = info[0].As<Napi::Number>();
    Napi::Number y = info[1].As<Napi::Number>();

    this->_wrappedClass_ = new cv::Point(x, y);
    return;
  }

  // TODO: implement 3D point
  if (length == 3) {
    Napi::TypeError::New(env, "3D points are not implemented.").ThrowAsJavaScriptException();
  }
}

cv::Point *Point::getInternalInstance() {
  return this->_wrappedClass_;
}

Napi::Value Point::getX(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  int x = this->_wrappedClass_->x;
  return Napi::Number::New(env, x);
}

Napi::Value Point::getY(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  int y = this->_wrappedClass_->y;
  return Napi::Number::New(env, y);
}
