#pragma force_active on
extern "C" {
extern int lbl_33_bss_8[2];
extern int lbl_33_bss_10[2];

void fn_33_2AB0() {
    lbl_33_bss_8[0] = 0xff;
    lbl_33_bss_8[1] = 0;
    lbl_33_bss_10[0] = 0xff;
    lbl_33_bss_10[1] = 1;
}
}

__declspec(section ".ctors") extern void* const fn_33_2AB0_ctor = (void*)fn_33_2AB0;
