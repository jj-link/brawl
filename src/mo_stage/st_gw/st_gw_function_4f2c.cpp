#pragma force_active on
extern "C" {
extern unsigned int lbl_63_bss_18[2];
extern unsigned int lbl_63_bss_20[2];

void fn_63_4F2C(void)
{
    lbl_63_bss_18[0] = 0xFF;
    lbl_63_bss_18[1] = 0;
    lbl_63_bss_20[0] = 0xFF;
    lbl_63_bss_20[1] = 1;
}
}

__declspec(section ".ctors") extern void* const fn_63_4F2C_ctor = (void*)fn_63_4F2C;
