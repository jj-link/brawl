#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_25740(void* member, s16 deleteFlag);
void* fn_27_CC0F0(void* member, s16 deleteFlag);

void* fn_103_69E0(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_27_25740(static_cast<u8*>(object) + 0x50, memberDeleteFlag);
        fn_27_CC0F0(object, memberDeleteFlag);
        if (deleteFlag > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
