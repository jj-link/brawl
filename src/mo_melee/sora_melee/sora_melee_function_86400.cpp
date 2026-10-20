#pragma force_active on
extern "C" {
extern signed char lbl_27_bss_19D8;
extern unsigned char lbl_27_bss_19E0[0x38];

void* fn_27_86400() {
    if (!lbl_27_bss_19D8) {
        lbl_27_bss_19D8 = 1;
    }
    return lbl_27_bss_19E0;
}
}
