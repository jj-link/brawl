#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_103_6070(void* member, s16 deleteFlag);
void* fn_103_404C(void* member, s16 deleteFlag);

void* fn_103_6004(void* object, s32 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_103_6070(static_cast<u8*>(object) + 0x24, memberDeleteFlag);
        fn_103_404C(object, memberDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
