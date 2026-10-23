#include <types.h>
#pragma force_active on

typedef struct Vec3 {
    float x, y, z;
} Vec3;

#define REG_ regist##er
#define ASM_ as##m

float fn_801ED1C4(REG_ const Vec3* a, REG_ const Vec3* b)
{
    REG_ float ayz, byz;
    REG_ float axy, bxy;
    REG_ float dxy, dyz;
    REG_ float dist;

    ASM_ {
        psq_l ayz, 4(a), 0, 0
        psq_l byz, 4(b), 0, 0
        psq_l axy, 0(a), 0, 0
        ps_sub dyz, ayz, byz
        psq_l bxy, 0(b), 0, 0
        ps_sub dxy, axy, bxy
        ps_mul  dyz,  dyz,  dyz
        ps_madd dist, dxy,  dxy, dyz
        ps_sum0 dist, dist, dyz, dyz
    }

    return dist;
}
