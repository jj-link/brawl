#pragma force_active on
extern void fn_80397748(void *, int, int);
extern void fn_803A1F10(void *);
extern unsigned char *lbl_805A1170;

void fn_803A1ED4(void) {
    unsigned char *p;

    p = lbl_805A1170 + 0x2E00;
    fn_80397748(p, 0, 0x800);
    fn_803A1F10(&p);
}
