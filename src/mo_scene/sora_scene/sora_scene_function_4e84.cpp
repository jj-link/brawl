#pragma force_active on
extern "C" {
extern unsigned int lbl_1_bss_8[2];
extern unsigned int lbl_1_bss_10[2];

void fn_1_4E84(void)
{
    lbl_1_bss_8[0] = 0xff;
    lbl_1_bss_8[1] = 0;
    lbl_1_bss_10[0] = 0xff;
    lbl_1_bss_10[1] = 1;
}
}

__declspec(section ".ctors") extern void* const fn_1_4E84_ctor = (void*)fn_1_4E84;
