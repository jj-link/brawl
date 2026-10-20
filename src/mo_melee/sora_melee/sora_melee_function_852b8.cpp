#pragma force_active on
extern "C" {
extern signed char lbl_27_bss_1300;
extern char lbl_27_bss_1304[];

void *fn_27_852B8(void)
{
    if (!lbl_27_bss_1300) {
        lbl_27_bss_1300 = 1;
    }
    return lbl_27_bss_1304;
}
}
