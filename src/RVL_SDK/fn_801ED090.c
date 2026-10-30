#include <types.h>
#pragma force_active on

typedef struct Vec {
    float x, y, z;
} Vec;

#define REG_ regist##er
#define ASM_ as##m

ASM_ f32 fn_801ED090(REG_ const Vec* a, REG_ const Vec* b)
{
    nofralloc

    psq_l  f2, 4(a), 0, 0
    psq_l  f3, 4(b), 0, 0
    ps_mul f2, f2, f3
    psq_l  f5, 0(a), 0, 0
    psq_l  f4, 0(b), 0, 0
    ps_madd f3, f5, f4, f2
    ps_sum0 f1, f3, f2, f2

    blr
}
