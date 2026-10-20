#include <types.h>
#pragma force_active on

extern "C" void fn_27_1A32F4(void* p, u32 v) {
    struct S {
        u32 a : 20;
        u32 b : 10;
        u32 c : 2;
    };
    S* s = (S*)((char*)p + 8);
    s->b = v >> 0;
}
