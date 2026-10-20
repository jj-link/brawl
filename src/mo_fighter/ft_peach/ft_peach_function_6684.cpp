#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_48BE8(void* member, s16 deleteFlag);
void* fn_27_47CCC(void* member, s16 deleteFlag);
void* fn_27_CB800(void* member, s16 deleteFlag);
void* fn_27_19FB24(void* member, s16 deleteFlag);
void* fn_27_19E5E0(void* member, s16 deleteFlag);

void* fn_103_6684(void* object, s32 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_27_48BE8(static_cast<u8*>(object) + 0xA14, memberDeleteFlag);
        fn_27_47CCC(static_cast<u8*>(object) + 0xA04, memberDeleteFlag);
        fn_27_CB800(static_cast<u8*>(object) + 0x908, memberDeleteFlag);
        fn_27_19FB24(static_cast<u8*>(object) + 0x78C, memberDeleteFlag);
        fn_27_19E5E0(object, memberDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
