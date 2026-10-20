#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_103_2024(void* member, s16 deleteFlag);
void* fn_27_C74E8(void* member, s16 deleteFlag);
void* fn_103_28DC(void* member, s16 deleteFlag);

void* fn_103_1FA0(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_103_2024(static_cast<u8*>(object) + 0x169E4, memberDeleteFlag);
        fn_27_C74E8(static_cast<u8*>(object) + 0x169D4, memberDeleteFlag);
        fn_103_28DC(object, 0);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
