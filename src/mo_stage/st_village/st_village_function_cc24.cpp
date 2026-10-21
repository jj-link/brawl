#pragma force_active on
extern "C" {
extern unsigned int lbl_70_bss_30[2];
extern unsigned int lbl_70_bss_38[2];

void fn_70_CC24(void)
{
    lbl_70_bss_30[0] = 0xFF;
    lbl_70_bss_30[1] = 0;
    lbl_70_bss_38[0] = 0xFF;
    lbl_70_bss_38[1] = 1;
}
}

__declspec(section ".ctors") extern void* const fn_70_CC24_ctor = (void*)fn_70_CC24;
