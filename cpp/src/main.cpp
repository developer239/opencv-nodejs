#include <napi.h>
#include "core/Point.h"
#include "core/Rect.h"
#include "core/RotatedRect.h"
#include "core/Size.h"
#include "core/Vec.h"
#include "core/Mat.h"
#include "functions/ImageRead.h"
#include "functions/ImageShow.h"
#include "functions/WaitKey.h"

// TODO: move to separate file START
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
// END

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  Point::Init(env, exports);
  Rect::Init(env, exports);
  RotatedRect::Init(env, exports);
  Size::Init(env, exports);
  Vec<Vec2dPolicy>::Init(env, exports);
  Vec<Vec3dPolicy>::Init(env, exports);
  Vec<Vec4dPolicy>::Init(env, exports);
  Mat::Init(env, exports);

  exports.Set(Napi::String::New(env, "imRead"), Napi::Function::New(env, ImageReadWorker::Create));
  exports.Set(Napi::String::New(env, "imShow"), Napi::Function::New(env, ImageShow));
  exports.Set(Napi::String::New(env, "waitKey"), Napi::Function::New(env, WaitKey));

  // TODO: move to separate file
  Napi::Object DATA_TYPE = Napi::Object::New(env);
  DATA_TYPE.Set("CV_8UC3", CV_8UC3);
  DATA_TYPE.Set("CV_8UC4", CV_8UC4);

  exports.Set(Napi::String::New(env, "DATA_TYPE"), DATA_TYPE);
  // END

  return exports;
}

NODE_API_MODULE(opencvnodejs, InitAll);

