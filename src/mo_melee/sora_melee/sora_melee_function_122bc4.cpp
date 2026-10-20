#include <types.h>
#pragma force_active on

typedef struct {
    u32 w0;
    u32 w1;
    u32 pad0 : 12;
    u32 f : 6;
    u32 pad1 : 14;
} FnWords;

extern "C" void fn_27_122BC4(FnWords* p, u32 v)
{
    p->f = v;
}
