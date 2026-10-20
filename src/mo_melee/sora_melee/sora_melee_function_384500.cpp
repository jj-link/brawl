#pragma force_active on
typedef unsigned char u8;

extern u8 lbl_27_bss_DAC[0x10];

extern "C" {
    void* fn_27_384500();
}

void* fn_27_384500() {
    return lbl_27_bss_DAC;
}
