#pragma force_active on
struct Object {
    unsigned char padding[0x90];
    unsigned int value;
};

extern "C" Object* lbl_27_bss_3210[];

extern "C" unsigned int fn_27_1494BC() {
    return lbl_27_bss_3210[0x3F]->value;
}
