#include <stddef.h>
#pragma force_active on

typedef struct Obj {
    int pad[2];
    int val;
} Obj;

extern "C" void* fn_41_34700(Obj* self, int idx)
{
    int t = (self->val >> 28) + idx;
    if (t >= 7) {
        t -= 7;
    }
    return (char*)self + (t << 4) + 0xc;
}
