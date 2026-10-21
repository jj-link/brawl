#pragma force_active on
extern "C" {
extern unsigned int lbl_2_bss_18[2];
extern unsigned int lbl_2_bss_20[2];

void fn_2_801C() {
    lbl_2_bss_18[0] = 0xFF;
    lbl_2_bss_18[1] = 0;
    lbl_2_bss_20[0] = 0xFF;
    lbl_2_bss_20[1] = 1;
}
}

__declspec(section ".ctors") extern void* const fn_2_801C_ctor = (void*)fn_2_801C;
