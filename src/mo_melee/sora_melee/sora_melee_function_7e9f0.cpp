#pragma force_active on
extern const float lbl_27_rodata_B70;

struct Pair {
    unsigned int a;
    unsigned int b;
};

extern "C" struct Pair fn_27_7E9F0() {
    union {
        float f[2];
        struct Pair p;
    } u;
    u.f[0] = lbl_27_rodata_B70;
    u.f[1] = lbl_27_rodata_B70;
    return u.p;
}
