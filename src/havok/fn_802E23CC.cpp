#pragma force_active on
#pragma fp_contract on
struct Obj { char pad0[0x130]; float c130,c134,c138,c13c; char pad1[0x10]; float c150; };
class Object_vptr_0 { public: virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(float*, float*, float); };
extern "C" float lbl_804864F0[];
extern const float lbl_805A4348, lbl_805A4354, lbl_805A4358, lbl_805A435C;
extern "C" double __frsqrte(double);
static inline float invsqrt(float x) {
    if (x <= lbl_805A4354) { union { unsigned int i; float f; } u; u.i = 0x7F800000; return u.f; }
    double d = __frsqrte(x);
    float r = (float)d;
    return (lbl_805A4348 * r) * (lbl_805A4358 - r * (x * r));
}
static inline void scale(float* a, float s) { a[0] *= s; a[1] *= s; a[2] *= s; a[3] *= s; }
extern "C" void fn_802E23CC(Obj* self, Object_vptr_0* p, float* out) {
    __attribute__((aligned(16))) float pts[8];
    __attribute__((aligned(16))) float mid[4];
    __attribute__((aligned(16))) float dv[4];
    p->slot3(lbl_804864F0, pts, lbl_805A4354);
    out[0] = pts[4] - pts[0];
    out[1] = pts[5] - pts[1];
    out[2] = pts[6] - pts[2];
    float len2a = out[0] * out[0] + out[1] * out[1] + out[2] * out[2];
    out[3] = pts[7] - pts[3];
    float inv1 = invsqrt(len2a);
    float half1 = lbl_805A4348 * (lbl_805A435C / inv1);
    mid[0] = pts[0] + pts[4];
    mid[1] = pts[1] + pts[5];
    mid[2] = pts[2] + pts[6];
    mid[3] = pts[3] + pts[7];
    scale(mid, lbl_805A4348);
    dv[0] = mid[0] - self->c130;
    dv[1] = mid[1] - self->c134;
    dv[2] = mid[2] - self->c138;
    dv[3] = mid[3] - self->c13c;
    float len2b = dv[0] * dv[0] + dv[1] * dv[1] + dv[2] * dv[2];
    float inv2 = invsqrt(len2b);
    half1 += lbl_805A435C / inv2;
    self->c150 = half1;
}