#include <types.h>
#pragma force_active on

struct fn_27_1AC130_Obj {
    u8 pad[0x18];
    s32 flag;
};

extern "C" {
void* fn_27_1AC130(fn_27_1AC130_Obj* obj, s32 idx)
{
    s32 n = (obj->flag >> 27) + idx;
    if (n >= 11) {
        n -= 11;
    }
    return (u8*)obj + (n << 4) + 0x1c;
}
}
