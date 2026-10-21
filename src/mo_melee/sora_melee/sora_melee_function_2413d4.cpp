#pragma force_active on
extern "C" unsigned int lbl_27_bss_5960[2];
extern "C" unsigned int lbl_27_bss_5968[2];

extern "C" void fn_27_2413D4()
{
    lbl_27_bss_5960[0] = 0xFF;
    lbl_27_bss_5960[1] = 0;
    lbl_27_bss_5968[0] = 0xFF;
    lbl_27_bss_5968[1] = 1;
}

__declspec(section ".ctors") extern void* const fn_27_2413D4_ctor = (void*)fn_27_2413D4;
