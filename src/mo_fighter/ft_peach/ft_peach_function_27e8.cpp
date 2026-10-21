#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_103_2188(void* member, s16 deleteFlag);
void* fn_103_2224(void* member, s16 deleteFlag);
void* fn_103_2264(void* member, s16 deleteFlag);
void* fn_103_2880(void* member, s16 deleteFlag);
void* fn_27_1A5FD8(void* member, s16 deleteFlag);

void* fn_103_27E8(void* object, s32 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_103_2188(static_cast<u8*>(object) + 0x9DC, memberDeleteFlag);
        fn_103_2224(static_cast<u8*>(object) + 0x9C0, memberDeleteFlag);
        fn_103_2264(static_cast<u8*>(object) + 0x914, memberDeleteFlag);
        fn_103_2880(static_cast<u8*>(object) + 0x488, memberDeleteFlag);
        if (object != nullptr) {
            fn_27_1A5FD8(object, memberDeleteFlag);
        }
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
