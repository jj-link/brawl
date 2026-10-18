#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_103_B628(void* member, s16 deleteFlag);
void __dl__FPv(void*);

void* fn_103_B688(void* object, s32 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_103_B628(static_cast<u8*>(object) + 8, memberDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
