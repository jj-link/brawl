#pragma force_active on
extern "C" {
extern unsigned int lbl_1_bss_50[2];
extern unsigned int lbl_1_bss_58[2];

void fn_1_8B98()
{
    lbl_1_bss_50[0] = 0xFF;
    lbl_1_bss_50[1] = 0;
    lbl_1_bss_58[0] = 0xFF;
    lbl_1_bss_58[1] = 1;
}
}

__declspec(section ".ctors") extern void* const fn_1_8B98_ctor = (void*)fn_1_8B98;
