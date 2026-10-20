#pragma force_active on
struct Inner {
    char pad[0x28];
    float value;
};

struct Outer {
    Inner *inner;
    unsigned char pad[6];
    unsigned char flag;
};

extern const float lbl_27_rodata_F48;

extern "C" void fn_27_1118AC(Outer *p, float f) {
    if (p->flag != 1) {
        return;
    }
    if (f < lbl_27_rodata_F48) {
        f = lbl_27_rodata_F48;
    }
    p->inner->value = f;
}
