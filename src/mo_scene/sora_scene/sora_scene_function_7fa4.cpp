#pragma force_active on
extern "C" {
extern unsigned int lbl_1_bss_38[2];
extern unsigned int lbl_1_bss_40[2];

void fn_1_7FA4(void)
{
    lbl_1_bss_38[0] = 0xFF;
    lbl_1_bss_38[1] = 0;
    lbl_1_bss_40[0] = 0xFF;
    lbl_1_bss_40[1] = 1;
}
}

__declspec(section ".ctors") extern void* const fn_1_7FA4_ctor = (void*)fn_1_7FA4;
