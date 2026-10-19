#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_6A3D8(void* member, s16 deleteFlag);
void* fn_27_199E3C(void* member, s16 deleteFlag);
void __dl__FPv(void*);

void* fn_103_6230(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_27_6A3D8(static_cast<u8*>(object) + 0x144, memberDeleteFlag);
        fn_27_199E3C(object, memberDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
