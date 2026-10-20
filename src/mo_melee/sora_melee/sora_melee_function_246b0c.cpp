#include <types.h>
#pragma force_active on

extern "C" {
extern void fn_27_246654(void*, int);
extern void __dl__FPv(void*);

void* fn_27_246B0C(void* a, s32 b) {
    if (a != 0) {
        fn_27_246654(a, 0);
        if (b > 0) {
            __dl__FPv(a);
        }
    }
    return a;
}
}
