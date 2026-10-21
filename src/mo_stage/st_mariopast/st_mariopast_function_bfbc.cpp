#pragma force_active on
extern "C" {
extern unsigned int lbl_48_bss_60[2];
extern unsigned int lbl_48_bss_68[2];

void fn_48_BFBC(void)
{
    lbl_48_bss_60[0] = 0xFF;
    lbl_48_bss_60[1] = 0;
    lbl_48_bss_68[0] = 0xFF;
    lbl_48_bss_68[1] = 1;
}
}

__declspec(section ".ctors") extern void* const fn_48_BFBC_ctor = (void*)fn_48_BFBC;
