#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_689B0(void* member, s16 deleteFlag);
void fn_27_1985B4(void* member, s16 deleteFlag);
void __dl__FPv(void* ptr);

void* fn_103_6348(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_27_689B0(static_cast<u8*>(object) + 0x7C, memberDeleteFlag);
        if (object != nullptr) {
            fn_27_1985B4(object, memberDeleteFlag);
        }
        if (static_cast<s16>(deleteFlag) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
