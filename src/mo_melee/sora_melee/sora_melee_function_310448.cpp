#include <types.h>
#pragma force_active on

extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_310448(void* p, s32 size) {
    if (p != 0 && size > 0)
        __dl__FPv(p);
    return p;
}
