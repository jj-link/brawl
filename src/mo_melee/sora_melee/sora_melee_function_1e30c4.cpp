#include <types.h>
#pragma force_active on

extern "C" void* fn_27_3544C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_1E30C4(void* p1, s32 p2) {
    if (p1) {
        fn_27_3544C(p1, -1);
        if (p2 > 0)
            __dl__FPv(p1);
    }
    return p1;
}
