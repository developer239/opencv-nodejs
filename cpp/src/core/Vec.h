#ifndef __VEC_H__
#define __VEC_H__

#include <napi.h>
#include <opencv2/opencv.hpp>

class Vec : public Napi::ObjectWrap<Vec> {
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports) {
    Napi::HandleScope scope(env);

    Napi::Function func = DefineClass(env, "Vec", {

    });

    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();

    exports.Set("Vec", func);
    return exports;
  }

  explicit Vec(const Napi::CallbackInfo &info) : Napi::ObjectWrap<Vec>(info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);
  }

private:
  static Napi::FunctionReference constructor;
};

#endif
