#pragma force_active on
extern "C" {
extern unsigned int lbl_66_bss_18[2];
extern unsigned int lbl_66_bss_20[2];

void fn_66_5874(void)
{
    lbl_66_bss_18[0] = 0xFF;
    lbl_66_bss_18[1] = 0;
    lbl_66_bss_20[0] = 0xFF;
    lbl_66_bss_20[1] = 1;
}
}

__declspec(section ".ctors") extern void* const fn_66_5874_ctor = (void*)fn_66_5874;
