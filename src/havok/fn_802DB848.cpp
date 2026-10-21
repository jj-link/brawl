#pragma force_active on
extern "C" {
void fn_802DB848(float* dst, const float* src) {
    dst[0] = -src[0];
    dst[1] = -src[1];
    dst[2] = -src[2];
    dst[3] = src[3];
}
}
