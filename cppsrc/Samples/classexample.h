#include <napi.h>
#include "actualclass.h"

class ClassExample : public Napi::ObjectWrap<ClassExample> {
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    ClassExample(const Napi::CallbackInfo& info);
    ActualClass* GetInternalInstance();

private:

    static Napi::FunctionReference constructor;
    Napi::Value GetValue(const Napi::CallbackInfo& info);
    Napi::Value Add(const Napi::CallbackInfo& info);

    // internal instance of ActualClass used to perform actual operations
    ActualClass *actualClass;
};
