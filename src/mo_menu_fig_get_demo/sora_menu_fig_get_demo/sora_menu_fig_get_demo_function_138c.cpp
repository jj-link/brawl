#pragma force_active on
extern "C" {
extern unsigned int lbl_26_bss_8[2];
extern unsigned int lbl_26_bss_10[2];

void fn_26_138C() {
    lbl_26_bss_8[0] = 0xFF;
    lbl_26_bss_8[1] = 0;
    lbl_26_bss_10[0] = 0xFF;
    lbl_26_bss_10[1] = 1;
}
}

__declspec(section ".ctors") extern void* const fn_26_138C_ctor = (void*)fn_26_138C;
