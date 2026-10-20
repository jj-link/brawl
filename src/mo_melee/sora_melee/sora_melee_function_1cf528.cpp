#include <types.h>
#pragma force_active on

struct Fn27Dest {
    u32 a;
    u32 b;
    s16 c;
    s16 d;
};

extern "C" void fn_27_1CF528(Fn27Dest* dst, const u32* src, u32 b, const s16* c, s16 d)
{
    dst->a = *src;
    dst->b = b;
    dst->c = *c;
    dst->d = d;
}
