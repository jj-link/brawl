#pragma force_active on
extern const float lbl_27_rodata_B70;

struct Pair {
    float a;
    float b;
};

extern "C" Pair fn_27_7FC8C() {
    Pair p;
    p.a = lbl_27_rodata_B70;
    p.b = lbl_27_rodata_B70;
    return p;
}
