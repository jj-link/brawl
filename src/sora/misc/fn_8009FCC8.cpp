#pragma force_active on
extern "C" void fn_8009FCC8(float* dst, const float* src1, const float* src2) {
    dst[0x27] = src1[0];
    dst[0x28] = src1[1];
    dst[0x29] = src1[2];
    dst[0x2A] = src2[0];
    dst[0x2B] = src2[1];
}
