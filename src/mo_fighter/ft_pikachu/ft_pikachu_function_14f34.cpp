#pragma force_active on
extern "C" {
extern const float lbl_98_rodata_A8;

struct Pair {
    float a;
    float b;
};

Pair fn_98_14F34(void) {
    Pair p;
    p.a = lbl_98_rodata_A8;
    p.b = lbl_98_rodata_A8;
    return p;
}
}
