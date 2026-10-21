#pragma force_active on
extern "C" {
extern unsigned int lbl_1_bss_1770[2];
extern unsigned int lbl_1_bss_1778[2];

void fn_1_1B720() {
    lbl_1_bss_1770[0] = 0xFF;
    lbl_1_bss_1770[1] = 0;
    lbl_1_bss_1778[0] = 0xFF;
    lbl_1_bss_1778[1] = 1;
}
}

__declspec(section ".ctors") extern void* const fn_1_1B720_ctor = (void*)fn_1_1B720;
