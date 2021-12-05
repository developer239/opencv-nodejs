#include <napi.h>
#include "core/Point.h"
#include "core/Rect.h"
#include "core/RotatedRect.h"
#include "core/Size.h"
#include "core/Vec.h"

struct Vec2dPolicy {
  constexpr static char *name = "Vec2";
  constexpr static int  Count  = 2;
  using ElementType = double;
};

struct Vec3dPolicy {
  constexpr static char *name = "Vec3";
  constexpr static int  Count  = 3;
  using ElementType = double;
};

struct Vec4dPolicy {
  constexpr static char *name = "Vec4";
  constexpr static int  Count  = 4;
  using ElementType = double;
};

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  Point::Init(env, exports);
  Rect::Init(env, exports);
  RotatedRect::Init(env, exports);
  Size::Init(env, exports);
  Vec<Vec2dPolicy>::Init(env, exports);
  Vec<Vec3dPolicy>::Init(env, exports);
  Vec<Vec4dPolicy>::Init(env, exports);

  return exports;
}

NODE_API_MODULE(opencvnodejs, InitAll);

