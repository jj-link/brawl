#pragma force_active on
extern "C" {
extern unsigned int lbl_27_bss_59E8[];
extern unsigned int lbl_27_bss_59F0[];

void fn_27_2585A8(void)
{
    lbl_27_bss_59E8[0] = 0xFF;
    lbl_27_bss_59E8[1] = 0;
    lbl_27_bss_59F0[0] = 0xFF;
    lbl_27_bss_59F0[1] = 1;
}
}

__declspec(section ".ctors") extern void* const fn_27_2585A8_ctor = (void*)fn_27_2585A8;
