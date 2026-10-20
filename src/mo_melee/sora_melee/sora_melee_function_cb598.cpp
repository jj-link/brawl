#include <types.h>
#pragma force_active on

typedef struct {
    u32 pad0:4;
    u32 f:2;
    u32 rest:26;
} Bits;

typedef struct {
    u32 w0;
    u32 w1;
    Bits c;
} Outer;

extern "C" {
void fn_27_CB598(Outer* o, u32 v)
{
    o->c.f = v;
}
}
