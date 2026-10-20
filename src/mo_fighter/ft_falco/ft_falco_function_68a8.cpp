#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_D2904(void* member, s16 deleteFlag);
void fn_108_6920(void* object, s16 deleteFlag);
void __dl__FPv(void*);

void* fn_108_68A8(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_27_D2904(static_cast<u8*>(object) + 0x318, memberDeleteFlag);
        void* base = object;
        if (base != nullptr) {
            s16 baseDeleteFlag = 0;
            fn_108_6920(base, baseDeleteFlag);
        }
        if (static_cast<s16>(deleteFlag) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
