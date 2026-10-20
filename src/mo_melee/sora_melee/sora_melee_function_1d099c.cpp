#include <types.h>
#pragma force_active on

struct S {
    u32 a : 4;
    u32 b : 4;
    u32 c : 24;
};

extern "C" void fn_27_1D099C(void* arg1, u32 arg2) {
    S* s = (S*)((u8*)arg1 + 8);
    s->b = arg2;
}
