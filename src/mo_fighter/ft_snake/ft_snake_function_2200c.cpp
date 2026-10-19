#include <types.h>
#pragma force_active on

extern "C" void fn_122_22068(void*, s16);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_2200C(void* array, s32 release) {
    if (array != 0) {
        fn_122_22068(array, -1);
        if ((s16)release > 0) {
            __dl__FPv(array);
        }
    }
    return array;
}
