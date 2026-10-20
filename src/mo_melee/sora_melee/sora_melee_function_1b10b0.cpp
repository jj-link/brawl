#include <types.h>
#pragma force_active on

struct S {
    s32 m0;
    s32 m4;
    s32 m8;
};

extern "C" void* fn_27_1B10B0(S* self, s32 idx) {
    s32 i = (self->m8 >> 27) + idx;
    if (i >= 8) {
        i -= 8;
    }
    return (char*)self + 0xc + (i << 4);
}
