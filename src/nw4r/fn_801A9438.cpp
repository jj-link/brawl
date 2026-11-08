#pragma force_active on
extern "C" {
extern const float lbl_805A33B8;
extern const float lbl_805A33BC;
extern const float lbl_805A33C0;
void fn_80162384(float*, float*, float);
inline void SinCos(float angle, float* s, float* c) { fn_80162384(s, c, lbl_805A33C0 * angle); }
void fn_801A9438(float* dest, const float* src) {
    float a;
    float b;
    SinCos(src[2], &a, &b);
    dest[0] = b;
    dest[1] = -a;
    dest[2] = lbl_805A33B8;
    dest[3] = a;
    dest[4] = a;
    dest[5] = b;
    dest[6] = lbl_805A33B8;
    dest[7] = lbl_805A33BC - b;
}
}