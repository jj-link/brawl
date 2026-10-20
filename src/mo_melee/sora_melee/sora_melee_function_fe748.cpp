#include <types.h>
#pragma force_active on

typedef struct {
    u8 pad[8];
    u32 field;
} fn_27_FE748_obj;

extern "C" {
s32 fn_27_FE748(fn_27_FE748_obj *p)
{
    u32 t = (p->field >> 25) & 0xF;
    return ((s32)(t << 28)) >> 29;
}
}
