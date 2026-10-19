#pragma force_active on
extern signed char lbl_27_bss_1AF0;
extern signed char lbl_27_bss_1AF4;

extern "C" {
signed char* fn_27_86828(void)
{
    if (lbl_27_bss_1AF0 == 0) {
        lbl_27_bss_1AF4 = -1;
        lbl_27_bss_1AF0 = 1;
    }
    return &lbl_27_bss_1AF4;
}
}
