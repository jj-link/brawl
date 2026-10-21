#pragma force_active on
extern unsigned char lbl_80494EE8[];

extern "C" void fn_80025940(unsigned int idx, float* src, float w) {
    if (idx < 7) {
        float* dst = (float*)(lbl_80494EE8 + idx * 0x68 + 0x58);
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
        dst[3] = w;
    }
}
