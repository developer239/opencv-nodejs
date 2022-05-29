#include "ImageRead.h"
#include "../core/Mat.h"
#include "../core/Point.h"

ImageReadWorker::ImageReadWorker(Napi::Env env, std::string &fileName) :
    Napi::AsyncWorker(env),
    input(fileName),
    result(),
    deferredPromise(Napi::Promise::Deferred::New(env)) {}

Napi::Value ImageReadWorker::Create(const Napi::CallbackInfo &info) {
  if (info.Length() != 1) {
    return Reject(info.Env(), "Expected file path");
  }

  if (!info[0].IsString()) {
    return Reject(info.Env(), "File path should be a string");
  }

  std::string input = info[0].As<Napi::String>().Utf8Value();

  if (input.size() < 1) {
    return Reject(info.Env(), "File path is empty");
  }

  // 💣
  auto *worker = new ImageReadWorker(info.Env(), input);
  worker->Queue();

  return worker->deferredPromise.Promise();
}

void ImageReadWorker::Execute() {
  cv::Mat image = cv::imread(input);
  result = &image;
}

Napi::Value ImageReadWorker::Reject(Napi::Env env, const char *message) {
  Napi::Promise::Deferred failed = Napi::Promise::Deferred::New(env);
  failed.Reject(Napi::Error::New(env, message).Value());

  return failed.Promise();
}

// TODO: possibly move to execute method?
void ImageReadWorker::OnOK() {
  Napi::Object imageObject = Mat::constructor.New({});
  Mat *image = Napi::ObjectWrap<Mat>::Unwrap(imageObject);

  image->bindMat(result);

  deferredPromise.Resolve(image->Value());
}

void ImageReadWorker::OnError(const Napi::Error &error) {
  deferredPromise.Reject(error.Value());
}
