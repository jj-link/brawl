#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_103_19EC(void* member, s16 deleteFlag);
void* fn_103_1DCC(void* member, s16 deleteFlag);
void* fn_103_1E68(void* member, s16 deleteFlag);
void* fn_103_1FA0(void* member, s16 deleteFlag);
void fn_27_125E20(void* object, s16 flag);

void* fn_103_194C(void* object, s32 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_103_19EC(static_cast<u8*>(object) + 0x18648, memberDeleteFlag);
        fn_103_1DCC(static_cast<u8*>(object) + 0x18190, memberDeleteFlag);
        fn_103_1E68(static_cast<u8*>(object) + 0x18154, memberDeleteFlag);
        fn_103_1FA0(static_cast<u8*>(object) + 0x194, memberDeleteFlag);
        fn_27_125E20(object, 0);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
