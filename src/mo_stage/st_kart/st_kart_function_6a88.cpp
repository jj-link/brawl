#pragma force_active on
struct St_kartObj {
    char pad00[0x24];
    float f24;
    float f28;
    float f2c;
    char pad30[8];
    int i38;
};

extern "C" {
extern signed char lbl_49_bss_D0;
extern St_kartObj lbl_49_bss_D8;
extern char lbl_49_bss_3C[];
extern const float lbl_49_rodata_90[];
void fn_49_4DF8(void);
void __register_global_object(void*, void*, void*);

void* fn_49_6A88(void) {
    if (lbl_49_bss_D0 == 0) {
        lbl_49_bss_D8.f24 = lbl_49_rodata_90[0];
        lbl_49_bss_D8.f28 = lbl_49_rodata_90[0];
        lbl_49_bss_D8.f2c = lbl_49_rodata_90[0];
        lbl_49_bss_D8.i38 = lbl_49_bss_D8.i38 & ~31;
        __register_global_object(&lbl_49_bss_D8, (void*)fn_49_4DF8, lbl_49_bss_3C);
        lbl_49_bss_D0 = 1;
    }
    return &lbl_49_bss_D8;
}
}
