#include <types.h>
#pragma force_active on

struct FE05C_Out {
    s32 a;
    s32 b;
    s16 c;
    s16 d;
};

extern "C" void fn_27_FE05C(FE05C_Out* out, const s32* src, s32 v, const s16* sp, s16 w)
{
    out->a = *src;
    out->b = v;
    out->c = *sp;
    out->d = w;
}
