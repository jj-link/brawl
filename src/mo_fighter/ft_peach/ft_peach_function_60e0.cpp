#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_B21D0(void* member, s16 deleteFlag);
void fn_27_CB4A0(void* object, s16 deleteFlag);

void* fn_103_60E0(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_27_B21D0(static_cast<u8*>(object) + 0x50, memberDeleteFlag);
        if (object != nullptr) {
            fn_27_CB4A0(object, memberDeleteFlag);
        }
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
