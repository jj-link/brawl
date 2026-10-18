#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_B81C4(void* member, s16 deleteFlag);
void* fn_103_2DD4(void* member, s16 deleteFlag);
void* fn_27_198034(void* member, s16 deleteFlag);

void* fn_103_2D54(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_27_B81C4(static_cast<u8*>(object) + 0xA4, memberDeleteFlag);
        fn_103_2DD4(static_cast<u8*>(object) + 0x48, memberDeleteFlag);
        if (object != nullptr) {
            fn_27_198034(object, memberDeleteFlag);
        }
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
