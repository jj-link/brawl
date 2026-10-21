#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_CB048(void* member, s16 deleteFlag);
void* fn_27_199214(void* member, s16 deleteFlag);
void* fn_27_A78FC(void* member, s16 deleteFlag);
void* fn_27_14E050(void* member, s16 deleteFlag);
void* fn_27_197EF4(void* member, s16 deleteFlag);

void* fn_103_2F5C(void* object, s32 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_27_CB048(static_cast<u8*>(object) + 0x220, memberDeleteFlag);
        fn_27_199214(static_cast<u8*>(object) + 0x94, memberDeleteFlag);
        fn_27_A78FC(static_cast<u8*>(object) + 0x78, memberDeleteFlag);
        fn_27_14E050(static_cast<u8*>(object) + 0x10, memberDeleteFlag);
        if (object != nullptr) {
            fn_27_197EF4(object, memberDeleteFlag);
        }
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
