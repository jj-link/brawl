#pragma force_active on
struct IntPair {
    int a;
    int b;
};

extern "C" {
extern const float lbl_117_rodata_B0;
}

extern "C" IntPair fn_117_154C4() {
    union {
        float f[2];
        IntPair p;
    } u;
    u.f[0] = lbl_117_rodata_B0;
    u.f[1] = lbl_117_rodata_B0;
    return u.p;
}
