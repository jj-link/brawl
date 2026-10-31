#pragma force_active on
#pragma fp_contract on

extern const float lbl_805A3E10;
extern const float lbl_805A3E40;
extern const float lbl_805A3E44;

extern "C" double __frsqrte(double);

static inline float lenSq(const float* v) {
    float t = v[1] * v[1];
    return v[0] * v[0] + t + v[2] * v[2];
}

static inline float rsqrtf(float x) {
    float scale = lbl_805A3E10;
    if (x != lbl_805A3E10) {
        if (x <= lbl_805A3E10) {
            union {
                unsigned int i;
                float f;
            } u;
            u.i = 0x7F800000;
            scale = u.f;
        } else {
            double e = __frsqrte(x);
            float r = (float)e;
            scale = (lbl_805A3E40 * r) * (lbl_805A3E44 - r * (x * r));
        }
    }
    return scale;
}

extern "C" void fn_80294C80(float* p) {
    float scale = rsqrtf(lenSq(p));
    p[0] = p[0] * scale;
    p[1] = p[1] * scale;
    p[2] = p[2] * scale;
    p[3] = p[3] * scale;
}
