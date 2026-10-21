#pragma force_active on
extern "C" {
extern int lbl_66_bss_170[2];
extern int lbl_66_bss_178[2];
}

extern "C" void fn_66_FB2C(void)
{
    lbl_66_bss_170[0] = 0xff;
    lbl_66_bss_170[1] = 0;
    lbl_66_bss_178[0] = 0xff;
    lbl_66_bss_178[1] = 1;
}

__declspec(section ".ctors") extern void* const fn_66_FB2C_ctor = (void*)fn_66_FB2C;
