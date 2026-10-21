#pragma force_active on
extern "C" {
extern unsigned int lbl_27_bss_7120[2];
extern unsigned int lbl_27_bss_7128[2];

void fn_27_2B2800()
{
    lbl_27_bss_7120[0] = 0xFF;
    lbl_27_bss_7120[1] = 0;
    lbl_27_bss_7128[0] = 0xFF;
    lbl_27_bss_7128[1] = 1;
}
}

__declspec(section ".ctors") extern void* const fn_27_2B2800_ctor = (void*)fn_27_2B2800;
