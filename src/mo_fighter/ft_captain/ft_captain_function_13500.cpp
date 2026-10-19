#pragma force_active on
extern "C" {
extern const float lbl_100_rodata_84;
}

struct FloatBits2 {
    unsigned int first;
    unsigned int second;
};

extern "C" FloatBits2 fn_100_13500() {
    union {
        float f[2];
        FloatBits2 bits;
    } p;
    p.f[0] = lbl_100_rodata_84;
    p.f[1] = lbl_100_rodata_84;
    return p.bits;
}
