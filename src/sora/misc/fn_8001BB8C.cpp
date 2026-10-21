#pragma force_active on
extern int lbl_8059FFE8;
extern int lbl_8059C52C;
extern unsigned char lbl_8059FFDC;

extern "C" int fn_8001BB8C() {
    lbl_8059C52C = 2;
    lbl_8059FFDC = 0;
    if (lbl_8059FFE8 != 0) {
        return ((int (*)(int))lbl_8059FFE8)(2);
    }
    return 2;
}
