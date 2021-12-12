#ifndef __IMAGE_READ_H__
#define __IMAGE_READ_H__

#include <sstream>
#include <napi.h>

#include <opencv2/opencv.hpp>

class ImageReadWorker : public Napi::AsyncWorker {
public:
  ImageReadWorker(Napi::Env env, std::string &fileName);

  static Napi::Value Create(const Napi::CallbackInfo &info);

  static Napi::Value Reject(Napi::Env env, const char *message);

protected:
  std::string input;
  cv::Mat *result;
  Napi::Promise::Deferred deferredPromise;

  void Execute() override;

  void OnOK() override;

  void OnError(const Napi::Error &error) override;
};

#endif
