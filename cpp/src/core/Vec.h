#ifndef __VEC_H__
#define __VEC_H__

#include <napi.h>
#include <opencv2/opencv.hpp>

template<class VariantPolicy>
class Vec : public Napi::ObjectWrap<Vec<VariantPolicy>> {
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);

  explicit Vec(const Napi::CallbackInfo &info);

private:
  static Napi::FunctionReference constructor;

  Napi::Value getX(const Napi::CallbackInfo &info);
  Napi::Value getY(const Napi::CallbackInfo &info);
  Napi::Value getZ(const Napi::CallbackInfo &info);
};

// TODO: Move to separate file START

template<class VariantPolicy>
Vec<VariantPolicy>::Vec(const Napi::CallbackInfo &info) : Napi::ObjectWrap<Vec<VariantPolicy>>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);
}

template<class VariantPolicy>
Napi::Object Vec<VariantPolicy>::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  Napi::Function func = Napi::ObjectWrap<Vec<VariantPolicy>>::DefineClass(env, VariantPolicy::name, {
      Napi::ObjectWrap<Vec<VariantPolicy>>::InstanceAccessor("x", &Vec<VariantPolicy>::getX, nullptr),
      Napi::ObjectWrap<Vec<VariantPolicy>>::InstanceAccessor("y", &Vec<VariantPolicy>::getY, nullptr),
      Napi::ObjectWrap<Vec<VariantPolicy>>::InstanceAccessor("z", &Vec<VariantPolicy>::getZ, nullptr),
  });

  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();

  exports.Set(VariantPolicy::name, func);
  return exports;
}

template<class VariantPolicy>
Napi::FunctionReference Vec<VariantPolicy>::constructor;

template<class VariantPolicy>
Napi::Value Vec<VariantPolicy>::getZ(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  return Napi::Number::New(env, 3);
}

template<class VariantPolicy>
Napi::Value Vec<VariantPolicy>::getY(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  return Napi::Number::New(env, 2);
}

template<class VariantPolicy>
Napi::Value Vec<VariantPolicy>::getX(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  return Napi::Number::New(env, 1);
}

// TODO: Move to separate file END

#endif
