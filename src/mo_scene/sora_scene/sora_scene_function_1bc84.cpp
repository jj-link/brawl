#pragma force_active on
extern "C" unsigned int lbl_1_bss_1780[2];
extern "C" unsigned int lbl_1_bss_1788[2];

extern "C" void fn_1_1BC84()
{
    lbl_1_bss_1780[0] = 0xFF;
    lbl_1_bss_1780[1] = 0;
    lbl_1_bss_1788[0] = 0xFF;
    lbl_1_bss_1788[1] = 1;
}

__declspec(section ".ctors") extern void* const fn_1_1BC84_ctor = (void*)fn_1_1BC84;
