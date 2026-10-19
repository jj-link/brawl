#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_565F0(void*, s16);
void* fn_103_6308(void*, s16);
void __dl__FPv(void*);

void* fn_103_629C(void* object, s32 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_27_565F0(static_cast<u8*>(object) + 0x14, memberDeleteFlag);
        fn_103_6308(object, memberDeleteFlag);

        if (static_cast<s16>(deleteFlag) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
