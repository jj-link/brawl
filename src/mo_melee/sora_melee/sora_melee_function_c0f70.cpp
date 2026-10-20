#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_C1490(void* p, s32 n);
void* fn_27_C1100(void* p, s32 n);
void __dl__FPv(void* p);
}

extern "C" void* fn_27_C0F70(char* p, s32 n) {
    if (p != 0) {
        fn_27_C1490(p + 0x3C, -1);
        fn_27_C1100(p, -1);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
