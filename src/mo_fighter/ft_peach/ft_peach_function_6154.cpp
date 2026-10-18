#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_150488(void* member, s16 deleteFlag);
void* fn_103_61D4(void* member, s16 deleteFlag);
void* fn_27_199A54(void* member, s16 deleteFlag);

void* fn_103_6154(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_27_150488(static_cast<u8*>(object) + 0x5B8, memberDeleteFlag);
        fn_103_61D4(static_cast<u8*>(object) + 0x584, memberDeleteFlag);
        if (object != nullptr) {
            fn_27_199A54(object, memberDeleteFlag);
        }
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
