#pragma force_active on
extern "C" {
extern unsigned int lbl_1_bss_68[2];
extern unsigned int lbl_1_bss_70[2];

void fn_1_E500()
{
    lbl_1_bss_68[0] = 0xFF;
    lbl_1_bss_68[1] = 0;
    lbl_1_bss_70[0] = 0xFF;
    lbl_1_bss_70[1] = 1;
}
}

__declspec(section ".ctors") extern void* const fn_1_E500_ctor = (void*)fn_1_E500;
