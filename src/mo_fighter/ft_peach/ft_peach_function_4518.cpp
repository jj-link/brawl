#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_103_3EE4(void* member, s16 deleteFlag);
void* fn_27_D2AA4(void* member, s16 deleteFlag);
void* fn_27_CD934(void* member, s16 deleteFlag);

void* fn_103_4518(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_103_3EE4(static_cast<u8*>(object) + 0x6C, memberDeleteFlag);
        u8* ptr = static_cast<u8*>(object) + 0x20;
        if (ptr != nullptr && ptr != nullptr && ptr != nullptr) {
            fn_27_D2AA4(ptr, memberDeleteFlag);
        }
        s16 flag = -1;
        fn_27_CD934(object, flag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
