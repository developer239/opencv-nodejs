#include "RotatedRect.h"
#include "Point.h"
#include "Size.h"

Napi::FunctionReference RotatedRect::constructor;

Napi::Object RotatedRect::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  Napi::Function func = DefineClass(env, "RotatedRect", {
      InstanceAccessor("angle", &RotatedRect::getAngle, nullptr),
      InstanceAccessor("center", &RotatedRect::getCenter, nullptr),
      InstanceAccessor("size", &RotatedRect::getSize, nullptr),
  });

  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("RotatedRect", func);
  return exports;
}

RotatedRect::RotatedRect(const Napi::CallbackInfo &info) : Napi::ObjectWrap<RotatedRect>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  // TODO: validate arguments

  Napi::Object pointObject = info[0].As<Napi::Object>();
  Point *pointObjectPointer = Napi::ObjectWrap<Point>::Unwrap(pointObject);
  cv::Point *point = pointObjectPointer->getInternalInstance();
  this->_wrappedClassCenter_ = pointObjectPointer;

  Napi::Object sizeObject = info[1].As<Napi::Object>();
  Size *sizeObjectPointer = Napi::ObjectWrap<Size>::Unwrap(sizeObject);
  cv::Size *size = sizeObjectPointer->getInternalInstance();
  this->_wrappedClassSize_ = sizeObjectPointer;

  Napi::Number angle = info[2].As<Napi::Number>();

  // 💣
  this->_wrappedClass_ = new cv::RotatedRect(*point, *size, angle);
}

cv::RotatedRect *RotatedRect::getInternalInstance() {
  return this->_wrappedClass_;
}

Napi::Value RotatedRect::getAngle(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  auto angle = this->_wrappedClass_->angle;
  return Napi::Number::New(env, angle);
}

Napi::Value RotatedRect::getCenter(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  return this->_wrappedClassCenter_->Value();
}

Napi::Value RotatedRect::getSize(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  return this->_wrappedClassSize_->Value();
}
