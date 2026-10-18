#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_103_3484(void* member, s16 deleteFlag);
void __dl__FPv(void* object);

void* fn_103_3424(void* object, s32 deleteFlag) {
    if (object != nullptr) {
        fn_103_3484(static_cast<u8*>(object) + 4, -1);
        if (static_cast<s16>(deleteFlag) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
