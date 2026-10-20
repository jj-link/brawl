#include <types.h>
#pragma force_active on

struct Fn27Out {
    u32 a;
    s32 b;
    s16 c;
    s16 d;
};

extern "C" void fn_27_FE19C(Fn27Out* out, u32* src, s32 v, s16* hp, s32 w) {
    src = (u32*)*src;
    s16 t = *hp;
    out->a = (u32)src;
    out->b = v;
    out->c = t;
    out->d = (s16)w;
}
