#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_4E038(void* member, s16 deleteFlag);
void* fn_27_4CAA0(void* member, s16 deleteFlag);
void* fn_27_CD4A4(void* object, s16 deleteFlag);
void __dl__FPv(void* object);

void* fn_103_65A0(void* object, s32 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_27_4E038(static_cast<u8*>(object) + 0xF0, memberDeleteFlag);
        fn_27_4CAA0(static_cast<u8*>(object) + 0x6C, memberDeleteFlag);
        fn_27_CD4A4(object, memberDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
