#pragma force_active on
struct Object {
    unsigned char padding[0xA4];
    unsigned int value;
};

struct State {
    unsigned char padding[0x228];
    Object* object;
    unsigned char remaining[0x6C];
};

extern "C" {
extern State lbl_27_bss_3210;

unsigned int fn_27_147F9C() {
    return lbl_27_bss_3210.object->value;
}
}
