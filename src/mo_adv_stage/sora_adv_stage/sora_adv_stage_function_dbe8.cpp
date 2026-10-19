#pragma force_active on
extern "C" {
extern void fn_27_234AF0(unsigned int*, unsigned int, unsigned char);
extern unsigned char lbl_40_data_1AA8[];

unsigned int* fn_40_DBE8(unsigned int* r3, unsigned int r4, unsigned int r5) {
    fn_27_234AF0(r3, r4, 0);
    r3[4] = r5;
    r3[1] = (unsigned int)lbl_40_data_1AA8;
    return r3;
}
}
