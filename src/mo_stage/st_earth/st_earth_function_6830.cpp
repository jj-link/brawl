#pragma force_active on
extern "C" {
extern unsigned int lbl_66_bss_28[2];
extern unsigned int lbl_66_bss_30[2];

void fn_66_6830(void)
{
    lbl_66_bss_28[0] = 0xFF;
    lbl_66_bss_28[1] = 0;
    lbl_66_bss_30[0] = 0xFF;
    lbl_66_bss_30[1] = 1;
}
}

__declspec(section ".ctors") extern void* const fn_66_6830_ctor = (void*)fn_66_6830;
