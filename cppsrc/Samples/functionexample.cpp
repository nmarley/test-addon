#include "functionexample.h"

namespace functionexample {

std::string hello() {
    return "Hello World";
}

int add(int a, int b) {
    return a + b;
}

Napi::String HelloWrapped(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::String returnValue = Napi::String::New(env, functionexample::hello());

    return returnValue;
}

Napi::Number AddWrapped(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    if (info.Length() < 2 || !info[0].IsNumber() || !info[1].IsNumber()) {
        Napi::TypeError::New(env, "Number Expected").ThrowAsJavaScriptException();
    }

    Napi::Number first = info[0].As<Napi::Number>();
    Napi::Number second = info[1].As<Napi::Number>();

    int returnValue = add(first.Int32Value(), second.Int32Value());

    return Napi::Number::New(env, returnValue);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set("hello", Napi::Function::New(env, HelloWrapped));
    exports.Set("add", Napi::Function::New(env, AddWrapped));

    return exports;
}

}
