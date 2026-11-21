#include <revolution/MTX/mtx.h>
#pragma force_active on
#pragma fp_contract on
extern "C" float lbl_805A4178;
struct Q { float x, y, z, w; };
extern "C" void fn_802D65E0(float *a, const Vec *b, Q *out) {
    char *base;
    __declspec(align(16)) float v[4];
    float by = b->y;
    float bz = b->z;
    float bx = b->x;
    v[0] = bz * a[6] + (bx * a[4] + by * a[5]);
    v[1] = bz * a[10] + (bx * a[8] + by * a[9]);
    v[2] = bz * a[14] + (bx * a[12] + by * a[13]);
    v[3] = lbl_805A4178;
    Q *p;
    int idx;
    float m;
    if (v[2] > v[1]) { idx = 32; m = v[2]; } else { idx = 16; m = v[1]; }
    if (v[0] > m) idx = 0;
    base = (char *)a + 16;
    float * t16_14 = (float *)(base + idx);
    out->x = *t16_14;
    p = (Q *)(base + idx);
    out->y = p->y;
    out->z = p->z;
    out->w = p->w;
    *(int *)&out->w = idx;
}
