#pragma force_active on
extern "C" {
extern const float lbl_805A33A0;
extern const float lbl_805A33A8;
extern const float lbl_805A33AC;

void fn_80162384(float*, float*, float);
}

inline void SinCos(float angle, float* s, float* c) {
    fn_80162384(s, c, lbl_805A33A8 * angle);
}

extern "C" void fn_801A8778(float* out, const float* in) {
    float a, b;
    SinCos(in[2], &a, &b);

    float v;
    float u;
    float c = lbl_805A33AC;

    v = c * a;
    u = c - (c * b);
    out[0] = b;
    out[1] = a;
    out[2] = lbl_805A33A0;
    out[3] = u - v;
    out[4] = -a;
    out[5] = b;
    out[6] = lbl_805A33A0;
    out[7] = u + v;
}
