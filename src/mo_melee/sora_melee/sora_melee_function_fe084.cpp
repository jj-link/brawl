#include <types.h>
#pragma force_active on

typedef struct {
    u32 a;
    u32 b;
    s16 c;
    s16 d;
} FE084Dst;

extern "C" void fn_27_FE084(FE084Dst* dst, u32* src, u32 val, s16* p, s16 val2)
{
    src = (u32*)*src;
    s16 c = *p;
    dst->a = (u32)src;
    dst->b = val;
    dst->c = c;
    dst->d = val2;
}
