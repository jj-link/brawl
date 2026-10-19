#include <types.h>
#pragma force_active on

extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_189E90(void* p, s32 n) {
    if (p) {
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
