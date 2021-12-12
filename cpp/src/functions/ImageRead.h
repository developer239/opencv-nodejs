#include <sstream>
#include <napi.h>
#include <unistd.h>

class ImageReadWorker : public Napi::AsyncWorker {
public:
  ImageReadWorker(Napi::Env env, std::string &name);

  static Napi::Value Create(const Napi::CallbackInfo &info);

  static Napi::Value Reject(Napi::Env env, const char *message);

protected:
  std::string input;
  std::string result;
  Napi::Promise::Deferred deferredPromise;

  void Execute() override;

  void OnOK() override;

  void OnError(const Napi::Error &error) override;
};

