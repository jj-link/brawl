#pragma force_active on
#pragma fp_contract on

extern const float lbl_805A3E10;
extern const float lbl_805A3E14;
extern const float lbl_805A3E40;
extern const float lbl_805A3E44;

extern "C" double __frsqrte(double);

extern "C" float fn_80295098(const float* v) {
    float t = v[1] * v[1];
    float x = v[0] * v[0] + t + v[2] * v[2];

    float scale;
    if (x <= lbl_805A3E10) {
        union {
            unsigned int i;
            float f;
        } u;
        u.i = 0x7F800000;
        scale = u.f;
    } else {
        double estimate = __frsqrte(x);
        float r = (float)estimate;
        scale = (lbl_805A3E40 * r) * (lbl_805A3E44 - r * (x * r));
    }
    return lbl_805A3E14 / scale;
}
