#pragma force_active on
extern "C" {

extern float lbl_805A33B8;
extern float lbl_805A33BC;

void fn_801A94C0(float* dst, const float* src) {
    float neg = -src[3];
    float a = lbl_805A33B8;
    float b = lbl_805A33BC;
    dst[0] = b;
    dst[1] = a;
    dst[2] = a;
    dst[3] = neg;
    dst[4] = a;
    dst[5] = b;
    dst[6] = a;
    dst[7] = src[4];
}

}
