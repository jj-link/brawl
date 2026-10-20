#include <types.h>
#pragma force_active on

struct Fn27Dst {
    u32 a;
    s32 b;
    s16 c;
    s16 d;
};

extern "C" {
void fn_27_FE174(Fn27Dst* dst, u32* src, s32 v, s16* hsrc, s16 w)
{
    src = (u32*)*src;
    s16 h = *hsrc;
    dst->a = (u32)src;
    dst->b = v;
    dst->c = h;
    dst->d = w;
}
}
