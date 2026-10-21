#pragma force_active on
extern unsigned char lbl_805A0415;

extern "C" int fn_800C8550(void) {
    unsigned char val = lbl_805A0415;
    lbl_805A0415 = 0;
    return val != 0;
}
