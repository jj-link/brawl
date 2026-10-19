#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void fn_103_1EE8(void* member, s16 deleteFlag);
void* fn_103_1F44(void* member, s16 deleteFlag);

void* fn_103_404C(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = 0;
        fn_103_1EE8(static_cast<u8*>(object) + 0x14, memberDeleteFlag);
        fn_103_1F44(static_cast<u8*>(object) + 0x8, memberDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
