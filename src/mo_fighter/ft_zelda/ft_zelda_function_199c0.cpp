#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_1A383C(void* member, s16 deleteFlag);
void __dl__FPv(void* ptr);

void* fn_104_199C0(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_27_1A383C(object, memberDeleteFlag);
        if (deleteFlag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
