#pragma force_active on
extern "C" {
extern unsigned int lbl_27_bss_5900[2];
extern unsigned int lbl_27_bss_5908[2];

void fn_27_23AA94(void)
{
    lbl_27_bss_5900[0] = 0xff;
    lbl_27_bss_5900[1] = 0;
    lbl_27_bss_5908[0] = 0xff;
    lbl_27_bss_5908[1] = 1;
}
}

__declspec(section ".ctors") extern void* const fn_27_23AA94_ctor = (void*)fn_27_23AA94;
