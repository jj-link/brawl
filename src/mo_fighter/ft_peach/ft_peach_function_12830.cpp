#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_103_128A0(void* member, s16 deleteFlag);
void* fn_103_12AD4(void* object, s16 deleteFlag);
void __dl__FPv(void* object);

void* fn_103_12830(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_103_128A0(static_cast<u8*>(object) + 0x19BC, memberDeleteFlag);
        s16 baseDeleteFlag = 0;
        fn_103_12AD4(object, baseDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
