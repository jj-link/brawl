#pragma force_active on
extern "C" {
extern int lbl_68_bss_160[2];
extern int lbl_68_bss_168[2];

void fn_68_FFCC(void)
{
    lbl_68_bss_160[0] = 255;
    lbl_68_bss_160[1] = 0;
    lbl_68_bss_168[0] = 255;
    lbl_68_bss_168[1] = 1;
}
}

__declspec(section ".ctors") extern void* const fn_68_FFCC_ctor = (void*)fn_68_FFCC;
