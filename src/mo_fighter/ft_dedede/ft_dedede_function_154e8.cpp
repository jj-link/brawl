#pragma force_active on
extern "C" {
extern const float lbl_117_rodata_B0;
}

struct DededeFloatPair {
    unsigned int lo;
    unsigned int hi;
};

extern "C" DededeFloatPair fn_117_154E8() {
    union {
        float f[2];
        DededeFloatPair p;
    } u;
    u.f[0] = lbl_117_rodata_B0;
    u.f[1] = lbl_117_rodata_B0;
    return u.p;
}
