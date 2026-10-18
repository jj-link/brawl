#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void fn_103_4950(void* member, s16 deleteFlag);

void* fn_103_48F0(void* object, s32 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_103_4950(static_cast<u8*>(object) + 4, memberDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
