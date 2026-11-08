#pragma force_active on
extern "C" int fn_803EC094(int);
extern int lbl_8059C52C;
extern unsigned char lbl_8059FFDC;
extern void (*lbl_8059FFE8)(int);

extern "C" void fn_8001BB1C(void) {
    int var_r31 = 0;
    lbl_8059C52C = 1;
    lbl_8059FFDC = 1;
    if (fn_803EC094(0x41) == 1) {
        var_r31 = 1;
    }
    if (var_r31 != 0) {
        lbl_8059C52C = 3;
    }
    if (lbl_8059FFE8 != 0) {
        lbl_8059FFE8(lbl_8059C52C);
    }
}
