#include <types.h>
#pragma force_active on

extern "C" void fn_27_8B600(void* p, short p2);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_27_14B548(void* p, s32 flag) {
    if (p != 0) {
        fn_27_8B600(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
