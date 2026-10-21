#pragma force_active on
extern "C" {
extern float lbl_805A33A0;
extern float lbl_805A33A4;

void fn_801A880C(float* dst, const float* src) {
    float a = src[3];
    float neg = -a;
    float c0 = lbl_805A33A0;
    float c4 = lbl_805A33A4;
    dst[0] = c4;
    dst[1] = c0;
    dst[2] = c0;
    dst[3] = neg;
    dst[4] = c0;
    dst[5] = c4;
    dst[6] = c0;
    dst[7] = src[4];
}
}
