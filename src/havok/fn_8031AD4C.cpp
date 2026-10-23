#pragma force_active on
#pragma fp_contract on

extern "C" void fn_8031AD4C(float* dest, const float* src1, const float* src2, float scale) {
    dest[0] = src1[0] + scale * src2[0];
    dest[1] = src1[1] + scale * src2[1];
    dest[2] = src1[2] + scale * src2[2];
    dest[3] = src1[3] + scale * src2[3];
}
