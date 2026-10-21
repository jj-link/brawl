#pragma force_active on
extern void fn_802819D0(void *buf, int size, void *src, ...);
extern void fn_80280840(void *p, void *q);
extern unsigned char lbl_8040F560[];

void *fn_80280B00(void *arg0, int arg1) {
    unsigned char sp8[0x400];

    fn_802819D0(sp8, 0x400, lbl_8040F560 + 0x18, arg1);
    fn_80280840(*(void **)((char *)arg0 + 8), sp8);
    return arg0;
}
