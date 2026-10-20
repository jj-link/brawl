#pragma force_active on
struct S {
    char pad0[0x11b];
    unsigned char f11b;
    char pad1[0x140 - 0x11c];
    void* f140;
    int f144;
};

extern "C" void* lbl_27_data_532B8;

extern "C" void fn_27_258218(S* p) {
    p->f11b = 1;
    p->f140 = lbl_27_data_532B8;
    p->f144 = 0;
}
