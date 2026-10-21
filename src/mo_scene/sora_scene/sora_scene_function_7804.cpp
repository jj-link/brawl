#pragma force_active on
extern "C" {
extern unsigned int lbl_1_bss_28[2];
extern unsigned int lbl_1_bss_30[2];

void fn_1_7804(void) {
    lbl_1_bss_28[0] = 0xff;
    lbl_1_bss_28[1] = 0;
    lbl_1_bss_30[0] = 0xff;
    lbl_1_bss_30[1] = 1;
}
}

__declspec(section ".ctors") extern void* const fn_1_7804_ctor = (void*)fn_1_7804;
