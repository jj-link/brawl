#include <types.h>
#pragma force_active on

typedef struct {
    u32 a : 14;
    u32 f : 7;
    u32 b : 11;
} Bits;

extern "C" {
void fn_27_CB69C(u32* self, u32 val)
{
    Bits* p = (Bits*)&self[2];
    p->f = val;
}
}
