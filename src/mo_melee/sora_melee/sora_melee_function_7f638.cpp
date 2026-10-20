#pragma force_active on
extern const float lbl_27_rodata_B70;

typedef unsigned int u32;

union FloatPair {
    float f[2];
    u32 u[2];
};

extern "C" {
union FloatPair fn_27_7F638(void) {
    union FloatPair x;
    x.f[0] = lbl_27_rodata_B70;
    x.f[1] = lbl_27_rodata_B70;
    return x;
}
}
