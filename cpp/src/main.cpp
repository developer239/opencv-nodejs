#include <napi.h>
#include "core/Point.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  Point::Init(env, exports);

  return exports;
}

NODE_API_MODULE(opencvnodejs, InitAll);
