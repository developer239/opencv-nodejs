#include "ImageRead.h"

ImageReadWorker::ImageReadWorker(Napi::Env env, std::string &name) :
    Napi::AsyncWorker(env),
    input(name),
    result(),
    deferredPromise(Napi::Promise::Deferred::New(env)) {}

Napi::Value ImageReadWorker::Create(const Napi::CallbackInfo &info) {
  if (info.Length() != 1) {
    return Reject(info.Env(), "MissingArgument");
  }

  if (!info[0].IsString()) {
    return Reject(info.Env(), "InvalidArgument");
  }

  std::string input = info[0].As<Napi::String>().Utf8Value();

  auto *worker = new ImageReadWorker(info.Env(), input);
  worker->Queue();

  return worker->deferredPromise.Promise();
}

void ImageReadWorker::Execute() {
  if (input.size() < 1) {
    SetError("EmptyName");
    return;
  }

  usleep(3000000);

  std::stringstream str;
  str << "hello, " << input;
  result = str.str();
}

Napi::Value ImageReadWorker::Reject(Napi::Env env, const char *message) {
  Napi::Promise::Deferred failed = Napi::Promise::Deferred::New(env);
  failed.Reject(Napi::Error::New(env, message).Value());

  return failed.Promise();
}

void ImageReadWorker::OnOK() {
  deferredPromise.Resolve(Napi::String::New(Env(), result));
}

void ImageReadWorker::OnError(const Napi::Error &error) {
  deferredPromise.Reject(error.Value());
}
