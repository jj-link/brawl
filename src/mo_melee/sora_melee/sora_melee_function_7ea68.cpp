#pragma force_active on
extern const float lbl_27_rodata_B70;

struct Pair {
    int a;
    int b;
};

extern "C" {
Pair fn_27_7EA68() {
    union {
        float f[2];
        Pair p;
    } u;
    u.f[0] = lbl_27_rodata_B70;
    u.f[1] = lbl_27_rodata_B70;
    return u.p;
}
}
