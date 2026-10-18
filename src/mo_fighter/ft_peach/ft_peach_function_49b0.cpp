#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_103_4A10(void* member, s16 deleteFlag);

void* fn_103_49B0(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_103_4A10(static_cast<u8*>(object) + 4, memberDeleteFlag);
        if (deleteFlag > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
