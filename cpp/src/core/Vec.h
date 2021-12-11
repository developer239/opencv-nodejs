#ifndef __VEC_H__
#define __VEC_H__

#include <napi.h>
#include <opencv2/opencv.hpp>
#include <any>

template<class VariantPolicy>
class Vec : public Napi::ObjectWrap<Vec<VariantPolicy>> {
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);

  explicit Vec(const Napi::CallbackInfo &info);

private:
  static Napi::FunctionReference constructor;

  cv::Vec<typename VariantPolicy::ElementType, VariantPolicy::Count> *_wrappedClass_;

  Napi::Value getX(const Napi::CallbackInfo &info);
  void setX(const Napi::CallbackInfo &info, const Napi::Value &value);

  Napi::Value getY(const Napi::CallbackInfo &info);
  void setY(const Napi::CallbackInfo &info, const Napi::Value &value);

  Napi::Value getZ(const Napi::CallbackInfo &info);
  void setZ(const Napi::CallbackInfo &info, const Napi::Value &value);

  Napi::Value getW(const Napi::CallbackInfo &info);
  void setW(const Napi::CallbackInfo &info, const Napi::Value &value);
};

// TODO: Move to separate file START

template<class VariantPolicy>
Vec<VariantPolicy>::Vec(const Napi::CallbackInfo &info) : Napi::ObjectWrap<Vec<VariantPolicy>>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  //
  // TODO: validate arguments
  //

  Napi::Number x = info[0].As<Napi::Number>();
  Napi::Number y = info[1].As<Napi::Number>();
  Napi::Number z = info[2].As<Napi::Number>();
  Napi::Number w = info[3].As<Napi::Number>();

  auto vec = new cv::Vec<double, VariantPolicy::Count>();
  vec->val[0] = x;
  vec->val[1] = y;

  if (VariantPolicy::Count == 3) {
    vec->val[2] = z;
  }

  if (VariantPolicy::Count == 4) {
    vec->val[2] = z;
    vec->val[3] = w;
  }

  this->_wrappedClass_ = vec;
}

template<class VariantPolicy>
Napi::Object Vec<VariantPolicy>::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  Napi::Function func = Napi::ObjectWrap<Vec<VariantPolicy>>::DefineClass(env, VariantPolicy::name, {
      Napi::ObjectWrap<Vec<VariantPolicy>>::InstanceAccessor("x", &Vec<VariantPolicy>::getX, &Vec<VariantPolicy>::setX),
      Napi::ObjectWrap<Vec<VariantPolicy>>::InstanceAccessor("y", &Vec<VariantPolicy>::getY, &Vec<VariantPolicy>::setY),
      Napi::ObjectWrap<Vec<VariantPolicy>>::InstanceAccessor("z", &Vec<VariantPolicy>::getZ, &Vec<VariantPolicy>::setZ),
      Napi::ObjectWrap<Vec<VariantPolicy>>::InstanceAccessor("w", &Vec<VariantPolicy>::getW, &Vec<VariantPolicy>::setW),
  });

  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();

  exports.Set(VariantPolicy::name, func);
  return exports;
}

template<class VariantPolicy>
Napi::FunctionReference Vec<VariantPolicy>::constructor;

template<class VariantPolicy>
Napi::Value Vec<VariantPolicy>::getX(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  auto x = this->_wrappedClass_->val[0];
  return Napi::Number::New(env, x);
}

template<class VariantPolicy>
Napi::Value Vec<VariantPolicy>::getY(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  auto y = this->_wrappedClass_->val[1];
  return Napi::Number::New(env, y);
}

template<class VariantPolicy>
Napi::Value Vec<VariantPolicy>::getZ(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  auto z = this->_wrappedClass_->val[2];
  return Napi::Number::New(env, z);
}

template<class VariantPolicy>
Napi::Value Vec<VariantPolicy>::getW(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  auto w = this->_wrappedClass_->val[3];
  return Napi::Number::New(env, w);
}

template<class VariantPolicy>
void Vec<VariantPolicy>::setX(const Napi::CallbackInfo &info, const Napi::Value &value) {
  const auto x = value.As<Napi::Number>();

  this->_wrappedClass_->val[0] = x;
}

template<class VariantPolicy>
void Vec<VariantPolicy>::setY(const Napi::CallbackInfo &info, const Napi::Value &value) {
  const auto y = value.As<Napi::Number>();

  this->_wrappedClass_->val[1] = y;
}

template<class VariantPolicy>
void Vec<VariantPolicy>::setZ(const Napi::CallbackInfo &info, const Napi::Value &value) {
  const auto z = value.As<Napi::Number>();

  this->_wrappedClass_->val[2] = z;
}

template<class VariantPolicy>
void Vec<VariantPolicy>::setW(const Napi::CallbackInfo &info, const Napi::Value &value) {
  const auto w = value.As<Napi::Number>();

  this->_wrappedClass_->val[3] = w;
}

// TODO: Move to separate file END

#endif
