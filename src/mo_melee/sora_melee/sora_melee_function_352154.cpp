#include <types.h>
#pragma force_active on

extern "C" {
extern void __dl__FPv(void*);

void* fn_27_352154(void* p, s32 count) {
    if (p && count > 0)
        __dl__FPv(p);
    return p;
}
}
