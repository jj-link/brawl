#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_103_C0DC(void* member, s16 deleteFlag);

void* fn_103_A60C(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_103_C0DC(static_cast<u8*>(object) + 4, memberDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
