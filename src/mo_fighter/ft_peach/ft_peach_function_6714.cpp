#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_48BE8(void* member, s16 deleteFlag);
void* fn_27_4742C(void* member, s16 deleteFlag);
void* fn_27_CB800(void* member, s16 deleteFlag);
void* fn_27_19FB24(void* member, s16 deleteFlag);
void* fn_27_19E398(void* member, s16 deleteFlag);

void* fn_103_6714(void* object, s32 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_27_48BE8(static_cast<u8*>(object) + 0x354, memberDeleteFlag);
        fn_27_4742C(static_cast<u8*>(object) + 0x344, memberDeleteFlag);
        fn_27_CB800(static_cast<u8*>(object) + 0x248, memberDeleteFlag);
        fn_27_19FB24(static_cast<u8*>(object) + 0xCC, memberDeleteFlag);
        fn_27_19E398(object, memberDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
