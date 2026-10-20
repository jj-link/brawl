#include <types.h>
#pragma force_active on

struct Fn27Out {
    u32 a;
    u32 b;
    s16 c;
    s16 d;
};

extern "C" void fn_27_FE034(Fn27Out* out, u32* src, u32 val, s16* half, s16 val2) {
    src = (u32*)*src;
    s16 h = *half;
    out->a = (u32)src;
    out->b = val;
    out->c = h;
    out->d = val2;
}
