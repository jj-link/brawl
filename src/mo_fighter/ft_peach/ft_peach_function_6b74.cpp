#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_22A38(void* member, s16 deleteFlag);
void fn_27_1A2910(void* member, s16 deleteFlag);

void* fn_103_6B74(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_27_22A38(static_cast<u8*>(object) + 0x34, memberDeleteFlag);
        fn_27_1A2910(object, memberDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
