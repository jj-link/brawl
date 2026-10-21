#pragma force_active on
struct Object {
    unsigned char padding[0xB4];
    unsigned int value;
};

struct Globals {
    unsigned char padding[0x228];
    Object* object;
    unsigned char tail[0x6C];
};

extern "C" Globals lbl_27_bss_3210;

extern "C" unsigned int fn_27_147FEC() {
    return lbl_27_bss_3210.object->value;
}
