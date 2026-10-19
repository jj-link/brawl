#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_103_232C(void* member, s16 deleteFlag);
void* fn_103_2188(void* object, s16 deleteFlag);
void __dl__FPv(void* object);

void* fn_103_22C0(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_103_232C(static_cast<u8*>(object) + 0x50, memberDeleteFlag);
        fn_103_2188(object, memberDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
