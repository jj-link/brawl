#pragma force_active on
#pragma fp_contract on
extern const float lbl_805A4650;
extern const float lbl_805A4660;
extern const float lbl_805A4664;
extern const float lbl_805A466C;
extern "C" double __frsqrte(double);
struct V4 { float x, y, z, w; } __attribute__((aligned(16)));
union FloatBits { unsigned int i; float f; };
static inline float invsqrt(float x, FloatBits& u) {
    if (x <= lbl_805A4650) {
        u.i = 0x7F800000;
        return u.f;
    }
    double estimate = __frsqrte(x);
    float r = (float)estimate;
    return (lbl_805A4664 * r) * (lbl_805A466C - r * (x * r));
}
static inline void cross(V4& o, const float* u, const float* v) {
    float x, y, z;
    x = u[1] * v[2] - u[2] * v[1];
    y = u[2] * v[0] - u[0] * v[2];
    z = u[0] * v[1] - u[1] * v[0];
    o.x = x; o.y = y; o.z = z; o.w = lbl_805A4650;
}
extern "C" void fn_803151F4(char* a, char* b, const float* v5, const float* v6, const float* v7, float* outDot, float* outLen) {
    V4 c1, c2;
    cross(c1, v7, v5);
    cross(c2, v7 + 4, v5);
    float l1 = c1.z * c1.z + (c1.x * c1.x + c1.y * c1.y);
    FloatBits u1, u2;
    float r1 = invsqrt(l1, u1);
    float v1 = *(float*)(a + 0xA0) * (lbl_805A4660 / r1);
    float l2 = c2.z * c2.z + (c2.x * c2.x + c2.y * c2.y);
    float r2 = invsqrt(l2, u2);
    float v2 = *(float*)(b + 0xA0) * (lbl_805A4660 / r2);
    *outLen = v1 + v2;
    *outDot = v6[2] * v5[2] + (v6[0] * v5[0] + v6[1] * v5[1]);
}