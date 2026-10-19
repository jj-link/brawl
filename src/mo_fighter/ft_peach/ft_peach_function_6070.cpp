#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_1A2524(void* member, s16 deleteFlag);
void* fn_103_400C(void* object, s16 deleteFlag);

void* fn_103_6070(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_27_1A2524(static_cast<u8*>(object) + 0x10, memberDeleteFlag);
        s16 baseDeleteFlag = 0;
        fn_103_400C(object, baseDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
