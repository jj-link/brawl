#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_103_BB44(void* member, s16 deleteFlag);
void* fn_103_BA10(void* base, s16 deleteFlag);
void __dl__FPv(void*);

void* fn_103_BBA4(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_103_BB44(static_cast<u8*>(object) + 0x134, memberDeleteFlag);
        void* base = object;
        if (base != nullptr) {
            s16 baseDeleteFlag = 0;
            fn_103_BA10(base, baseDeleteFlag);
        }
        if (static_cast<s16>(deleteFlag) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
