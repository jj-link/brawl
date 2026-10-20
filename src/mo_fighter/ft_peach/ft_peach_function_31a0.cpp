#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_93100(void*, short);
void* fn_103_3228(void* object, s16 deleteFlag);
void* fn_27_19F4C4(void*, short);
void* fn_27_1A55B0(void*, short);

void* fn_103_31A0(void* object, s32 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_27_93100(static_cast<u8*>(object) + 0xFE80, memberDeleteFlag);
        fn_103_3228(static_cast<u8*>(object) + 0x7C, memberDeleteFlag);
        fn_27_19F4C4(static_cast<u8*>(object) + 0x20, memberDeleteFlag);
        fn_27_1A55B0(object, memberDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
