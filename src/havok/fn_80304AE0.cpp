#include <nw4r/math/math_arithmetic.h>
#pragma force_active on

typedef struct Vec4 {
    float x, y, z, w;
} Vec4 __attribute__((aligned(16)));

extern "C" double __fabs(double);

extern "C" void fn_80304AE0(void* object, const Vec4* vecs, int a, int b, Vec4* out)
{
    const Vec4* va = &vecs[a];
    char* base = (char*)object;
    float sb = *(float*)(base + b * 4 + 0xC0);
    const Vec4* vb = &vecs[b];
    float sa = *(float*)(base + a * 4 + 0xC0);
    Vec4 p, q;
    p.x = sb * va->x;
    p.y = sb * va->y;
    p.z = sb * va->z;
    p.w = sb * va->w;
    q.x = sa * vb->x;
    q.y = sa * vb->y;
    q.z = sa * vb->z;
    q.w = sa * vb->w;
    out->x = (float)__fabs((double)(p.x - q.x));
    out->y = (float)__fabs((double)(p.y - q.y));
    out->z = (float)__fabs((double)(p.z - q.z));
    out->w = (float)__fabs((double)(p.w - q.w));
}
