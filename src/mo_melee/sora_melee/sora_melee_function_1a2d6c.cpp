#include <types.h>
#pragma force_active on

typedef struct fn27_1A2D6C_s {
    u8 pad[8];
    u32 flags;
} fn27_1A2D6C_s;

extern "C" {
s32 fn_27_1A2D6C(fn27_1A2D6C_s* p)
{
    u32 v = (p->flags >> 27) & 7;
    return ((s32)(v << 29)) >> 30;
}
}
