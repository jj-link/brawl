#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_13C90(void* member, s16 deleteFlag);
void* fn_27_21038(void* member, s16 deleteFlag);
void* fn_103_4518(void* member, s16 deleteFlag);

void* fn_103_12CBC(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_27_13C90(static_cast<u8*>(object) + 0x9C, memberDeleteFlag);
        fn_27_21038(static_cast<u8*>(object) + 0x88, memberDeleteFlag);
        fn_103_4518(object, memberDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
