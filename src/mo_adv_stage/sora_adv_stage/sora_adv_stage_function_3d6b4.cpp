#pragma force_active on
extern "C" {
extern unsigned int lbl_40_bss_29E0[2];
extern unsigned int lbl_40_bss_29E8[2];

void fn_40_3D6B4(void)
{
    lbl_40_bss_29E0[0] = 0xFF;
    lbl_40_bss_29E0[1] = 0;
    lbl_40_bss_29E8[0] = 0xFF;
    lbl_40_bss_29E8[1] = 1;
}
}

__declspec(section ".ctors") extern void* const fn_40_3D6B4_ctor = (void*)fn_40_3D6B4;
