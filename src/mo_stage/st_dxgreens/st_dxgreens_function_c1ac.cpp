#pragma force_active on
extern "C" void fn_79_C1AC(void);

extern int lbl_79_bss_140[2];
extern int lbl_79_bss_148[2];

extern "C" void fn_79_C1AC(void)
{
    lbl_79_bss_140[0] = 0xFF;
    lbl_79_bss_140[1] = 0;
    lbl_79_bss_148[0] = 0xFF;
    lbl_79_bss_148[1] = 1;
}

__declspec(section ".ctors") extern void* const fn_79_C1AC_ctor = (void*)fn_79_C1AC;
