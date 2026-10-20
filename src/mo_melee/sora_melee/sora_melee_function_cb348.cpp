#include <types.h>
#pragma force_active on

struct fn_27_CB348_obj {
    u32 pad0;
    u32 pad4;
    u32 top : 8;
    u32 rest : 24;
};

extern "C" {
void fn_27_CB348(fn_27_CB348_obj *base, u32 val)
{
    base->top = val;
}
}
