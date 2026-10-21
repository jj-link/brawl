#pragma force_active on
extern "C" {
extern int lbl_27_bss_4678[2];
extern int lbl_27_bss_4680[2];

void fn_27_14FB50(void)
{
    lbl_27_bss_4678[0] = 0xFF;
    lbl_27_bss_4678[1] = 0;
    lbl_27_bss_4680[0] = 0xFF;
    lbl_27_bss_4680[1] = 1;
}
}

__declspec(section ".ctors") extern void* const fn_27_14FB50_ctor = (void*)fn_27_14FB50;
