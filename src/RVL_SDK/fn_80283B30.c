#include <types.h>
#pragma fp_contract on
#pragma force_active on

extern void fn_80283ACC(f32 *m);

void fn_80283B30(f32 (*dst)[4], const f32 (*src)[4], const f32 (*m)[4])
{
    f32 tmp[4][4] __attribute__((aligned(16)));
    const f32* a;
    const f32* t;
    f32* d;
    int i;
    int j;

    tmp[0][0] = src[0][0];
    tmp[0][1] = src[0][1];
    tmp[0][2] = src[0][2];
    tmp[0][3] = src[0][3];
    tmp[1][0] = src[1][0];
    tmp[1][1] = src[1][1];
    tmp[1][2] = src[1][2];
    tmp[1][3] = src[1][3];
    tmp[2][0] = src[2][0];
    tmp[2][1] = src[2][1];
    tmp[2][2] = src[2][2];
    tmp[2][3] = src[2][3];
    tmp[3][0] = src[3][0];
    tmp[3][1] = src[3][1];
    tmp[3][2] = src[3][2];
    tmp[3][3] = src[3][3];

    fn_80283ACC(&tmp[0][0]);
    for (i = 0; i < 4; i++) {
        a = m[i];
        d = dst[i];
        for (j = 0; j < 4; j++) {
            t = tmp[j];
            { f32 value = t[0] * a[0] + t[1] * a[1] + t[2] * a[2] + t[3] * a[3]; d[j] = value; }
        }
    }
}