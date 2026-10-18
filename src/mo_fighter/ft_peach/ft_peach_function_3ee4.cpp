#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_103_3F44(void* member, s16 deleteFlag);

void* fn_103_3EE4(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_103_3F44(static_cast<u8*>(object) + 0x0C, memberDeleteFlag);
        if (deleteFlag > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
