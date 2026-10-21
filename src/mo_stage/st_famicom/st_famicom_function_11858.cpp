#pragma force_active on
extern "C" {
extern unsigned int lbl_68_bss_170[2];
extern unsigned int lbl_68_bss_178[2];

void fn_68_11858(void)
{
    lbl_68_bss_170[0] = 0xFF;
    lbl_68_bss_170[1] = 0;
    lbl_68_bss_178[0] = 0xFF;
    lbl_68_bss_178[1] = 1;
}
}

__declspec(section ".ctors") extern void* const fn_68_11858_ctor = (void*)fn_68_11858;
