#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_103_2188(void*, s16);
void* fn_103_2224(void*, s16);
void* fn_103_2264(void*, s16);
void* fn_27_C7770(void*, s16);

void* fn_103_2388(void* object, s32 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_103_2188(static_cast<u8*>(object) + 0xDC, memberDeleteFlag);
        fn_103_2224(static_cast<u8*>(object) + 0xC0, memberDeleteFlag);
        fn_103_2264(static_cast<u8*>(object) + 0x14, memberDeleteFlag);
        if (object != nullptr) {
            fn_27_C7770(object, memberDeleteFlag);
        }
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
