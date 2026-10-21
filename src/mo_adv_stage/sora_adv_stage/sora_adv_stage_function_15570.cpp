#pragma force_active on
extern "C" {
extern unsigned int lbl_40_bss_7B0[2];
extern unsigned int lbl_40_bss_7B8[2];

void fn_40_15570() {
    lbl_40_bss_7B0[0] = 0xFF;
    lbl_40_bss_7B0[1] = 0;
    lbl_40_bss_7B8[0] = 0xFF;
    lbl_40_bss_7B8[1] = 1;
}
}

__declspec(section ".ctors") extern void* const fn_40_15570_ctor = (void*)fn_40_15570;
