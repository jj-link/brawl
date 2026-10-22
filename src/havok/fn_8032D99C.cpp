#pragma force_active on
#pragma fp_contract on

extern const float lbl_805A48B8;
extern const float lbl_805A48BC;
extern const float lbl_805A48C0;

extern "C" double __frsqrte(double);

extern "C" void fn_8032D99C(float* p) {
    float s = p[0] * p[0] + p[1] * p[1];
    s = p[2] * p[2] + s;
    s = p[3] * p[3] + s;

    float scale = lbl_805A48B8;
    if (s != lbl_805A48B8) {
        if (s <= lbl_805A48B8) {
            union {
                unsigned int i;
                float f;
            } u;
            u.i = 0x7F800000;
            scale = u.f;
        } else {
            float r = (float)__frsqrte(s);
            scale = (lbl_805A48BC * r) * (lbl_805A48C0 - r * (s * r));
        }
    }

    p[0] = p[0] * scale;
    p[1] = p[1] * scale;
    p[2] = p[2] * scale;
    p[3] = p[3] * scale;
}
