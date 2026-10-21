#pragma force_active on
extern void fn_80397748(void *, int, int);
extern void fn_803A1DF4(void *);
extern unsigned char *lbl_805A1170;

void fn_803A1CA0(void) {
    unsigned char *sp8;

    sp8 = lbl_805A1170 + 0x2A00;
    fn_80397748(sp8, 0, 0x360);
    fn_803A1DF4(&sp8);
}
