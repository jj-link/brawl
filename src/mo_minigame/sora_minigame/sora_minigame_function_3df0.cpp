#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern u32 lbl_20_bss_8;
void fn_802EFFA0(void *);
void fn_802EFFA4(void *);

void fn_20_3DF0() {
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
