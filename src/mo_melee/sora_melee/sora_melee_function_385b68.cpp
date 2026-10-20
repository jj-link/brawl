#include <types.h>
#pragma force_active on

struct fn_27_385B68_Obj {
    u8 pad[8];
    u32 pad0 : 20;
    u32 field : 11;
    u32 pad1 : 1;
};

extern "C" {
s32 fn_27_385B68(fn_27_385B68_Obj* p)
{
    return (s32)(p->field << 21) >> 22;
}
}
