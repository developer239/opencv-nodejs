#include "Mat.h"

Napi::FunctionReference Mat::constructor;

Napi::Object Mat::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  Napi::Function func = DefineClass(env, "Mat", {
      InstanceAccessor("cols", &Mat::getCols, nullptr),
      InstanceAccessor("rows", &Mat::getRows, nullptr),
      InstanceMethod("type", &Mat::type, napi_default),
      InstanceMethod("at", &Mat::at, napi_default),
  });

  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("Mat", func);
  return exports;
}

// TODO: optimize and refactor
Mat::Mat(const Napi::CallbackInfo &info) : Napi::ObjectWrap<Mat>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  int length = info.Length();

  if (length == 0) {
    this->_wrappedClass_ = new cv::Mat();
    return;
  }

  if (length == 2) {
    Napi::Number rows = info[0].As<Napi::Number>();
    Napi::Number cols = info[1].As<Napi::Number>();

    this->_wrappedClass_ = new cv::Mat(rows, cols, CV_8UC3);
    return;
  }

  if (length == 3) {
    Napi::Number rows = info[0].As<Napi::Number>();
    Napi::Number cols = info[1].As<Napi::Number>();
    Napi::Number dataType = info[2].As<Napi::Number>();

    this->_wrappedClass_ = new cv::Mat(rows, cols, dataType);
    return;
  }

  if (length == 4) {
    Napi::Number rows = info[0].As<Napi::Number>();
    Napi::Number cols = info[1].As<Napi::Number>();
    Napi::Number dataType = info[2].As<Napi::Number>();
    auto fillValue = info[3].As<Napi::Array>();

    cv::Scalar fillScalar = cv::Scalar(1, 2, 3);

    // TODO: validate scalar length with dataType

    for (int i = 0; i < fillValue.Length(); i++) {
      fillScalar[i] = fillValue.Get(i).ToNumber().Int32Value();
    }

    this->_wrappedClass_ = new cv::Mat(rows, cols, dataType, fillScalar);

    return;
  }

  return;
}

cv::Mat *Mat::getInternalInstance() {
  return this->_wrappedClass_;
}

void Mat::bindMat(cv::Mat *matrix) {
  this->_wrappedClass_ = matrix;
}

Napi::Value Mat::getCols(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  int cols = this->_wrappedClass_->cols;
  return Napi::Number::New(env, cols);
}

Napi::Value Mat::getRows(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  int rows = this->_wrappedClass_->rows;
  return Napi::Number::New(env, rows);
}

Napi::Value Mat::type(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  int type = this->_wrappedClass_->type();

  return Napi::Number::New(env, type);
}

Napi::Value Mat::at(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Y and X arguments expected.").ThrowAsJavaScriptException();
  }

  Napi::Number y = info[0].As<Napi::Number>();
  Napi::Number x = info[1].As<Napi::Number>();

  unsigned char p = this->_wrappedClass_->at<char>(y, x);

  return Napi::Number::New(env, (int)p);
}
