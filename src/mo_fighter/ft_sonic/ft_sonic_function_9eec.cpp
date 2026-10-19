#include <stddef.h>
#pragma force_active on

extern "C" void* __dt__21ftExtendParamAccesserFv(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" {
void* fn_123_9EEC(void* this_, short flags) {
    if (this_ != NULL) {
        __dt__21ftExtendParamAccesserFv(this_, 0);
        if (flags > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}
}
