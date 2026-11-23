#pragma force_active on
#pragma fp_contract on

struct Vec4 { float x, y, z, w; };
struct Vec3 { float x, y, z; };

extern const float lbl_805A48E4;
extern const float lbl_805A48E8;
extern const float lbl_805A48EC;
extern const float lbl_805A48F0;
extern const float lbl_805A48F4;
extern const float lbl_805A48F8;

extern "C" double __frsqrte(double);
extern "C" void fn_80285910(Vec4*, const Vec3*);

union Bits { unsigned int i; float f; };
static inline float rsqrt(float x, Bits* u) {
    if (x <= lbl_805A48E4) {
        u->i = 0x7F800000;
        return u->f;
    }
    double d = __frsqrte(x);
    float r = (float)d;
    return lbl_805A48E8 * r * (lbl_805A48EC - r * (x * r));
}

static inline float rsqrt2(float x) {
    union { unsigned int i; float f; } u;
    if (x <= lbl_805A48E4) {
        u.i = 0x7F800000;
        return u.f;
    }
    float r = (float)__frsqrte(x);
    return lbl_805A48E8 * r * (lbl_805A48EC - r * (x * r));
}

extern "C" void fn_8032E570(Vec4* out, const Vec3* a, const Vec3* b, float alpha) {
    __attribute__((aligned(16))) Vec4 v;
    float dot = a->x*b->x + a->y*b->y + a->z*b->z;
    float value = (lbl_805A48F0 - alpha) + alpha * dot;

    if (value > lbl_805A48F4) {
        out->w = lbl_805A48F0;
        out->x = lbl_805A48E4;
        out->y = lbl_805A48E4;
        out->z = lbl_805A48E4;
        return;
    }
    if (value < lbl_805A48F8) {
        fn_80285910(out, a);
        return;
    }

    Bits inf;
    float f5 = lbl_805A48E8 * (lbl_805A48F0 + value);
    float inv = rsqrt(f5, &inf);
    float f10 = lbl_805A48F0 / inv;
    float x = a->y*b->z - a->z*b->y;
    float y = a->z*b->x - a->x*b->z;
    float z = a->x*b->y - a->y*b->x;
    float f11 = lbl_805A48E4;
    float f12 = (lbl_805A48E8 * alpha) / f10;
    v.x = x * f12;
    v.y = y * f12;
    v.z = z * f12;
    v.w = f10;
    float n2 = v.x*v.x + v.y*v.y + v.z*v.z + v.w*v.w;

    if (n2 != f11) {
        if (n2 <= lbl_805A48E4) {
            union { unsigned int i; float f; } u;
            u.i = 0x7F800000;
            f11 = u.f;
        } else {
            double d = __frsqrte(n2);
            float r = (float)d;
            f11 = lbl_805A48E8 * r * (lbl_805A48EC - r * (n2 * r));
        }
    }

    v.x = v.x * f11;
    v.y = v.y * f11;
    v.z = v.z * f11;
    v.w = v.w * f11;
    out->x = v.x;
    out->y = v.y;
    out->z = v.z;
    out->w = v.w;
}
