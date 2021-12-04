#include <napi.h>
#include "core/Point.h"
#include "core/Rect.h"
#include "core/RotatedRect.h"
#include "core/Size.h"
#include "core/Vec.h"

struct Vec2dPolicy {
  constexpr static char name[] = "Vec2d";
  constexpr static int  Count  = 2;
  using ElementType = double;
};

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  Point::Init(env, exports);
  Rect::Init(env, exports);
  RotatedRect::Init(env, exports);
  Size::Init(env, exports);

  Vec::Init(env, exports);

  return exports;
}

NODE_API_MODULE(opencvnodejs, InitAll);
