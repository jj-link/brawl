#include <types.h>
#pragma force_active on

typedef struct {
    u32 pad0;
    u32 pad4;
    u32 value;
} fn_27_1A5A80_Obj;

extern "C" s32 fn_27_1A5A80(fn_27_1A5A80_Obj *p)
{
    u32 x = p->value;
    u32 r = (x << 20) | (x >> 12);
    r &= 0xFFE00000;
    return (s32)r >> 22;
}
