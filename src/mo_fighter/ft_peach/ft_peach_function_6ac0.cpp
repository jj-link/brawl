#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_13C90(void* member, s16 deleteFlag);
void* fn_27_21038(void* member, s16 deleteFlag);
void* fn_103_6B74(void* member, s16 deleteFlag);
void* fn_103_6BE0(void* member, s16 deleteFlag);
void* fn_103_6C3C(void* member, s16 deleteFlag);
void* fn_103_6C98(void* member, s16 deleteFlag);
void* fn_103_6CF4(void* member, s16 deleteFlag);
void* fn_103_6D50(void* member, s16 deleteFlag);

void* fn_103_6AC0(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_27_13C90(static_cast<u8*>(object) + 0x224, memberDeleteFlag);
        fn_103_6B74(static_cast<u8*>(object) + 0x1E8, memberDeleteFlag);
        fn_27_21038(static_cast<u8*>(object) + 0x1D8, memberDeleteFlag);
        fn_103_6BE0(static_cast<u8*>(object) + 0x1B8, memberDeleteFlag);
        fn_103_6C3C(static_cast<u8*>(object) + 0x198, memberDeleteFlag);
        fn_103_6C98(static_cast<u8*>(object) + 0x160, memberDeleteFlag);
        fn_103_6CF4(static_cast<u8*>(object) + 0xC4, memberDeleteFlag);
        fn_103_6D50(object, memberDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
