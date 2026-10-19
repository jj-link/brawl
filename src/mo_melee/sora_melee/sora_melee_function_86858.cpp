#pragma force_active on
extern "C" {
extern signed char lbl_27_bss_1AF5;
extern signed char lbl_27_bss_1AF8[8];

void* fn_27_86858() {
    if (lbl_27_bss_1AF5 == 0) {
        lbl_27_bss_1AF8[0] = -1;
        lbl_27_bss_1AF5 = 1;
    }
    return lbl_27_bss_1AF8;
}
}
