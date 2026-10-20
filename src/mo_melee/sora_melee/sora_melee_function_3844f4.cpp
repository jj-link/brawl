#pragma force_active on
typedef struct bss_loc_DAC_t {
    char pad[0x10];
} bss_loc_DAC_t;

extern bss_loc_DAC_t lbl_27_bss_DAC;

extern "C" void* fn_27_3844F4(void) {
    return &lbl_27_bss_DAC;
}
