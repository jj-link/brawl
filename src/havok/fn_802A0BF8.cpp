#pragma force_active on
#pragma fp_contract on

extern const float lbl_805A3EB0;
extern const float lbl_805A3EB4;
extern const float lbl_805A3EB8;
extern const float lbl_805A3EBC;

extern "C" double __frsqrte(double);

extern "C" float sqrt__6hkMathFf(float x) {
    float denom;
    if (x <= lbl_805A3EB4) {
        union {
            unsigned int i;
            float f;
        } u;
        u.i = 0x7F800000;
        denom = u.f;
    } else {
        float r = (float)__frsqrte(x);
        denom = (lbl_805A3EB8 * r) * (lbl_805A3EBC - r * (x * r));
    }
    return lbl_805A3EB0 / denom;
}
