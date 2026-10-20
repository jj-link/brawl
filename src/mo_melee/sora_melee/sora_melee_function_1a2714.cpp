#include <types.h>
#pragma force_active on

struct Fn27Obj {
    u32 pad[2];
    u32 bits;
};

extern "C" s32 fn_27_1A2714(Fn27Obj* p)
{
    return (s32)((p->bits << 8) & 0xF8000000) >> 28;
}
