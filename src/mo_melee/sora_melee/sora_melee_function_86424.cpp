#pragma force_active on
typedef signed char s8;
typedef unsigned char u8;

extern "C" {
extern s8 lbl_27_bss_1A18;
extern u8 lbl_27_bss_1A20[0x38];

void* fn_27_86424(void) {
    if (lbl_27_bss_1A18 == 0) {
        lbl_27_bss_1A18 = 1;
    }
    return lbl_27_bss_1A20;
}
}
