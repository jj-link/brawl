#pragma force_active on
extern "C" {
    extern void *fn_27_6F6E8(void *a, void *b);

    void *fn_27_6A650(void *p)
    {
        extern unsigned char lbl_27_bss_110[0x10];
        return fn_27_6F6E8(lbl_27_bss_110, p);
    }
}
