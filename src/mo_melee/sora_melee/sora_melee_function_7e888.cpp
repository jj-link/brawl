#pragma force_active on
typedef unsigned int u32;

extern const float lbl_27_rodata_B70;

struct Pair {
    u32 a;
    u32 b;
};

extern "C" Pair fn_27_7E888() {
    union {
        float f[2];
        Pair p;
    } u;
    float v = lbl_27_rodata_B70;
    u.f[0] = v;
    u.f[1] = v;
    return u.p;
}
