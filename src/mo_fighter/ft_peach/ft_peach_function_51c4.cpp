#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_1A20EC(void* member, s16 deleteFlag);
void* fn_103_3C7C(void* object, s16 deleteFlag);

void* fn_103_51C4(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_27_1A20EC(static_cast<u8*>(object) + 0x10, memberDeleteFlag);
        s16 baseDeleteFlag = 0;
        fn_103_3C7C(object, baseDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
