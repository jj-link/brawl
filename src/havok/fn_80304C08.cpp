#pragma force_active on
#pragma fp_contract on

extern const float lbl_805A45C4;
extern const float lbl_805A45C8;
extern const float lbl_805A45D0;
extern const float lbl_805A45D4;

extern "C" double __frsqrte(double);

static inline float invsqrt(float x)
{
    if (x <= lbl_805A45C4) {
        union {
            unsigned int i;
            float f;
        } u;
        u.i = 0x7F800000;
        return u.f;
    }

    float r = (float)__frsqrte(x);
    return (lbl_805A45D0 * r) *
           (lbl_805A45D4 - r * (x * r));
}

extern "C" void fn_80304C08(float* p)
{
    p[0] = invsqrt(lbl_805A45C8 + p[0]);
    p[1] = invsqrt(lbl_805A45C8 + p[1]);
    p[2] = invsqrt(lbl_805A45C8 + p[2]);
    p[3] = lbl_805A45C4;
}
