#pragma force_active on
extern "C" void fn_80162384(float*, float*, float);
extern const float lbl_805A33A0;
extern const float lbl_805A33A8;
extern const float lbl_805A33AC;
inline void SinCos(float angle, float* s, float* c) { fn_80162384(s, c, lbl_805A33A8 * angle); }
extern "C" void fn_801A8900(float* dst, const float* src) {
    float s, c;
    SinCos(src[2], &s, &c);
    float z = lbl_805A33A0;
    float half = lbl_805A33AC;
    float b = half * s;
    float a = half - half * c;
    dst[0] = c;
    dst[1] = s;
    dst[2] = z;
    dst[3] = (a - b) - src[3];
    dst[4] = -s;
    dst[5] = c;
    dst[6] = z;
    dst[7] = src[4] + (a + b);
}