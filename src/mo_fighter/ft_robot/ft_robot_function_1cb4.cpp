#include <types.h>
#pragma force_active on

extern "C" {
void fn_120_1B3C(void* p, s16 flag);
void __dl__FPv(void* p);
void* fn_120_1CB4(void* p, s16 flag);
}

void* fn_120_1CB4(void* p, s16 flag) {
    if (p != 0) {
        fn_120_1B3C(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
