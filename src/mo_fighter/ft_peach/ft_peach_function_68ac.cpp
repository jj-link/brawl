#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_B5324(void*, s16);
void* fn_103_6924(void* object, s16 deleteFlag);
void* fn_103_6984(void* object, s16 deleteFlag);

void* fn_103_68AC(void* object, s32 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_27_B5324(static_cast<u8*>(object) + 0x30, memberDeleteFlag);
        fn_103_6924(static_cast<u8*>(object) + 0x18, memberDeleteFlag);
        fn_103_6984(static_cast<u8*>(object) + 4, memberDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
