#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_C1100(void* p, s32 n);
void __dl__FPv(void*);

void* fn_27_C1490(void* p, s32 n) {
    if (p) {
        fn_27_C1100(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
