#ifndef __VEC_H__
#define __VEC_H__

#include <napi.h>
#include <opencv2/opencv.hpp>

template<class Policy>
class Vec : public Napi::ObjectWrap<Vec<Policy >> {
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

  template<class...Args, typename std::enable_if<sizeof...(Args) == Policy::Count, int>::type = 0>
  explicit Vec(Args... args) {

  }

private:
  static Napi::FunctionReference constructor;
};

#endif
