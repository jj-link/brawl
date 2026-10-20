#include <types.h>
#pragma force_active on

struct fn_27_FE0D4_S {
    s32 a;
    s32 b;
    s16 c;
    s16 d;
};

extern "C" void fn_27_FE0D4(fn_27_FE0D4_S* s, s32* src, s32 b, s16* c, s16 d)
{
    src = (s32*)*src;
    s16 cv = *c;
    s->a = (s32)src;
    s->b = b;
    s->c = cv;
    s->d = d;
}
