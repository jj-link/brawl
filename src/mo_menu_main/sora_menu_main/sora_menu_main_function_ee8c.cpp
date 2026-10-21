#pragma force_active on
extern "C" {
extern int lbl_2_bss_28[2];
extern int lbl_2_bss_30[2];

void fn_2_EE8C() {
    lbl_2_bss_28[0] = 0xFF;
    lbl_2_bss_28[1] = 0;
    lbl_2_bss_30[0] = 0xFF;
    lbl_2_bss_30[1] = 1;
}
}

__declspec(section ".ctors") extern void* const fn_2_EE8C_ctor = (void*)fn_2_EE8C;
