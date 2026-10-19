#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_10424(void* member, s16 deleteFlag);
void* fn_27_19A97C(void* member, s16 deleteFlag);

void* fn_103_2EE8(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_27_10424(static_cast<u8*>(object) + 0x7C, memberDeleteFlag);
        if (object != nullptr) {
            fn_27_19A97C(object, memberDeleteFlag);
        }
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
