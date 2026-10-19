#pragma force_active on
extern "C" {
extern void *lbl_20_bss_8;
void fn_802EFFA0(void *);
void fn_802EFFA4(void *);

void fn_20_2E08() {
    void *p = *(void **)((char *)lbl_20_bss_8 + 0x4C0);
    p = *(void **)((char *)p + 0x10);
    p = *(void **)((char *)p + 0x0C);
    fn_802EFFA0(p);

    p = *(void **)((char *)lbl_20_bss_8 + 0x4C0);
    p = *(void **)((char *)p + 0x10);
    p = *(void **)((char *)p + 0x0C);
    fn_802EFFA4(p);
}
}
