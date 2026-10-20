#include <types.h>
#pragma force_active on

struct Fn27Obj {
    u8 pad[8];
    u32 val;
};

extern "C" {
s32 fn_27_295B78(Fn27Obj* p)
{
    return (s32)((p->val << 3) & 0xF0000000) >> 29;
}
}
