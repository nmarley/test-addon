#include <napi.h>

Napi::Object InitAll(Napi::Env, Napi::Object exports) {
    return exports;
}

NODE_API_MODULE(testaddon, InitAll);
