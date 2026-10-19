#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_103_B688(void* object, s16 deleteFlag);
void* fn_103_B568(void* object, s16 deleteFlag);

void* fn_103_B6E8(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_103_B688(static_cast<u8*>(object) + 0x60, memberDeleteFlag);
        s16 baseDeleteFlag = 0;
        fn_103_B568(object, baseDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
