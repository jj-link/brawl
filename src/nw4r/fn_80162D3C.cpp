#pragma force_active on
struct Vec3 { float x; float y; float z; };
extern "C" void fn_80162D3C(Vec3* dst, const Vec3* src, unsigned int count) {
    float c;
    float b;
    float a;
    float t;
    unsigned int i;
    const Vec3* p = src + 1;
    a = src->x;
    b = src->y;
    c = p[-1].z;
    dst->x = a;
    dst->y = b;
    dst->z = c;
    dst[1].x = a;
    dst[1].y = b;
    dst[1].z = c;
    for (i = 1; i < count; i++, p++) {
        t = p->x;
        if (t < dst->x) dst->x = t;
        else if (t > dst[1].x) dst[1].x = t;
        t = p->y;
        if (t < dst->y) dst->y = t;
        else if (t > dst[1].y) dst[1].y = t;
        t = p->z;
        if (t < dst->z) dst->z = t;
        else if (t > dst[1].z) dst[1].z = t;
    }
}