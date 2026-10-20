#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_103_3EE4(void* member, s16 deleteFlag);
void* fn_103_6DC8(void* member, s16 deleteFlag);
void* fn_27_CD934(void* member, s16 deleteFlag);

void* fn_103_6D50(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_103_3EE4(static_cast<u8*>(object) + 0xAC, memberDeleteFlag);
        fn_103_6DC8(static_cast<u8*>(object) + 0x20, memberDeleteFlag);
        fn_27_CD934(object, memberDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
