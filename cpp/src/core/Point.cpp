#include "Point.h"

Napi::FunctionReference Point::constructor;

Napi::Object Point::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  Napi::Function func = DefineClass(env, "Point2", {
      InstanceAccessor("x", &Point::getX, &Point::setX),
      InstanceAccessor("y", &Point::getY, &Point::setY),
      InstanceMethod("add", &Point::add),
      InstanceMethod("subtract", &Point::subtract)
  });

  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("Point2", func);
  return exports;
}

Point::Point(const Napi::CallbackInfo &info) : Napi::ObjectWrap<Point>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  int length = info.Length();

  if (length == 0) {
    Napi::TypeError::New(env, "Arguments expected.").ThrowAsJavaScriptException();
  }

  // Initialize from reference
  if (length == 1) {
    Napi::Object object = info[0].As<Napi::Object>();
    Point *pointObject = Napi::ObjectWrap<Point>::Unwrap(object);
    cv::Point *point = pointObject->getInternalInstance();

    // 💣
    this->_wrappedClass_ = new cv::Point(point->x, point->y);
    return;
  }

  // Initialize from values
  if (length == 2) {
    Napi::Number x = info[0].As<Napi::Number>();
    Napi::Number y = info[1].As<Napi::Number>();

    // 💣
    this->_wrappedClass_ = new cv::Point(x, y);
    return;
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

void Point::setX(const Napi::CallbackInfo &info, const Napi::Value &value) {
  const auto x = value.As<Napi::Number>();

  this->_wrappedClass_->x = x;
}

void Point::setY(const Napi::CallbackInfo &info, const Napi::Value &value) {
  const auto y = value.As<Napi::Number>();

  this->_wrappedClass_->y = y;
}

Napi::Value Point::add(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() < 1) {
    Napi::TypeError::New(env, "Argument expected.").ThrowAsJavaScriptException();
  }

  Napi::Object pointObject = info[0].As<Napi::Object>();
  Point *pointToAdd = Napi::ObjectWrap<Point>::Unwrap(pointObject);

  cv::Point resultPoint = *this->getInternalInstance() + *pointToAdd->getInternalInstance();

  Napi::Number x = Napi::Number::New(env, resultPoint.x);
  Napi::Number y = Napi::Number::New(env, resultPoint.y);

  Napi::Object point = constructor.New({x, y});

  return point;
}

Napi::Value Point::subtract(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() < 1) {
    Napi::TypeError::New(env, "Argument expected.").ThrowAsJavaScriptException();
  }

  Napi::Object pointObject = info[0].As<Napi::Object>();
  Point *pointToAdd = Napi::ObjectWrap<Point>::Unwrap(pointObject);

  cv::Point resultPoint = *this->getInternalInstance() - *pointToAdd->getInternalInstance();

  Napi::Number x = Napi::Number::New(env, resultPoint.x);
  Napi::Number y = Napi::Number::New(env, resultPoint.y);

  Napi::Object point = constructor.New({x, y});

  return point;
}
