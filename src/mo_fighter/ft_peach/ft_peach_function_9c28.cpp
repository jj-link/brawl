#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* __dt__21ftExtendParamAccesserFv(void* object, s16 deleteFlag);
void __dl__FPv(void* ptr);

void* fn_103_9C28(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        __dt__21ftExtendParamAccesserFv(object, 0);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
