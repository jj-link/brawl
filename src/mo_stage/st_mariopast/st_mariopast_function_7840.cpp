#pragma force_active on
extern "C" {
extern unsigned int lbl_48_bss_28[2];
extern unsigned int lbl_48_bss_30[2];

void fn_48_7840(void)
{
    lbl_48_bss_28[0] = 0xFF;
    lbl_48_bss_28[1] = 0;
    lbl_48_bss_30[0] = 0xFF;
    lbl_48_bss_30[1] = 1;
}
}

__declspec(section ".ctors") extern void* const fn_48_7840_ctor = (void*)fn_48_7840;
