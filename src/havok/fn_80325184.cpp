#pragma force_active on
#pragma fp_contract on
extern const float lbl_805A47C8;
extern const float lbl_805A47CC;
extern const float lbl_805A47D4;
extern const float lbl_805A47D8;
extern "C" double __frsqrte(double);
struct V4 { float x, y, z, w; } __attribute__((aligned(16)));
static inline void sub(V4& r, const V4& a, const V4& b) {
    r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; r.w = a.w - b.w;
}
static inline float dot3(const V4& a, const V4& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
static inline void cross(V4& n, const V4& a, const V4& b) {
    float nz, nx, ny;
    nx = a.y * b.z - a.z * b.y;
    ny = a.z * b.x - a.x * b.z;
    nz = a.x * b.y - a.y * b.x;
    n.x = nx; n.y = ny; n.z = nz; n.w = lbl_805A47C8;
}
union FloatBits { unsigned int i; float f; };
static inline float invsqrt(float x, FloatBits& u) {
    if (x <= lbl_805A47C8) { u.i = 0x7f800000; return u.f; }
    double estimate = __frsqrte(x);
    float r = (float)estimate;
    return (lbl_805A47D4 * r) * (lbl_805A47D8 - r * (x * r));
}
extern "C" void fn_80325184(const V4* p, float* out) {
    V4 a, b, n;
    sub(a, p[0], p[1]);
    sub(b, p[2], p[1]);
    float aa = dot3(a, a);
    float bb = dot3(b, b);
    float ab = dot3(b, a);
    float det = aa * bb;
    float abab = ab * ab;
    det = det - abab;
    float inv = lbl_805A47CC / det;
    out[0] = aa * inv;
    out[1] = bb * inv;
    out[2] = ab * inv;
    cross(n, a, b);
    FloatBits u;
    float r = invsqrt(dot3(n, n), u);
    float t = lbl_805A47CC / r;
    out[3] = lbl_805A47CC / t;
}