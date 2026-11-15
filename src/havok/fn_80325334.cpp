#pragma force_active on
#pragma fp_contract on
extern const float lbl_805A47C8;
extern const float lbl_805A47D4;
extern const float lbl_805A47D8;
extern "C" double __frsqrte(double);
struct V4 { float x, y, z, w; } __attribute__((aligned(16)));
static inline void sub(V4& r, const V4& a, const V4& b) {
    r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; r.w = a.w - b.w;
}
static inline void cross(V4& n, const V4& e2, const V4& e3) {
    float nz, nx, ny;
    nx = e2.y * e3.z - e2.z * e3.y;
    ny = e2.z * e3.x - e2.x * e3.z;
    nz = e2.x * e3.y - e2.y * e3.x;
    n.x = nx; n.y = ny; n.z = nz; n.w = lbl_805A47C8;
}
static inline float lensq(float x, float y, float z) {
    return x * x + y * y + z * z;
}
union FloatBits { unsigned int i; float f; };
static inline float invsqrt(float x, FloatBits& u) {
    if (x <= lbl_805A47C8) {
        u.i = 0x7F800000;
        return u.f;
    }
    double estimate = __frsqrte(x);
    float r = (float)estimate;
    return (lbl_805A47D4 * r) * (lbl_805A47D8 - r * (x * r));
}
extern "C" void fn_80325334(const float* m, float* out) {
    V4 e2, e3, e1, n;
    const V4* v = (const V4*)m;
    sub(e2, v[2], v[1]);
    sub(e3, v[0], v[2]);
    sub(e1, v[1], v[0]);
    cross(n, e2, e3);
    float l[4];
    l[0] = lensq(e2.x, e2.y, e2.z);
    l[1] = lensq(e3.x, e3.y, e3.z);
    l[2] = lensq(e1.x, e1.y, e1.z);
    l[3] = lensq(n.x, n.y, n.z);
    float s[4];
    FloatBits u3, u2, u1, u0;
    float x3, x2, x1;
    s[0] = invsqrt(l[0], u0);
    x1 = l[1]; s[1] = invsqrt(x1, u1);
    x2 = l[2]; s[2] = invsqrt(x2, u2);
    x3 = l[3]; s[3] = invsqrt(x3, u3);
    out[0] = s[0];
    out[1] = s[1];
    out[2] = s[2];
    out[3] = s[3];
    out[4] = s[3] * l[3];
}