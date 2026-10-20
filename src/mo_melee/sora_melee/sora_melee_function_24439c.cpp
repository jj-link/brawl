#include <types.h>
#pragma force_active on

extern "C" {
extern void __dl__FPv(void*);
extern void fn_27_2429BC(void*, int);

void* fn_27_24439C(void* arg1, s32 arg2) {
    if (arg1) {
        fn_27_2429BC(arg1, 0);
        if (arg2 > 0) {
            __dl__FPv(arg1);
        }
    }
    return arg1;
}
}
