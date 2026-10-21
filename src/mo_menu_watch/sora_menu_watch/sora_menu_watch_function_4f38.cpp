#pragma force_active on
extern "C" {
extern unsigned int lbl_15_bss_8[2];
extern unsigned int lbl_15_bss_10[2];

void fn_15_4F38() {
    lbl_15_bss_8[0] = 0xff;
    lbl_15_bss_8[1] = 0;
    lbl_15_bss_10[0] = 0xff;
    lbl_15_bss_10[1] = 1;
}
}

__declspec(section ".ctors") extern void* const fn_15_4F38_ctor = (void*)fn_15_4F38;
