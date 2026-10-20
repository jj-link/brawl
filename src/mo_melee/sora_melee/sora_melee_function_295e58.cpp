#include <types.h>
#pragma force_active on

struct fn_27_295E58_Obj {
    u8 pad[8];
    u32 flags;
};

extern "C" {
s32 fn_27_295E58(fn_27_295E58_Obj* obj)
{
    return (s32)((obj->flags << 3) & 0xF0000000) >> 29;
}
}
