#pragma force_active on
extern "C" {

struct StaticObj {
    unsigned char pad[0x24];
    float f24;
    float f28;
    float f2c;
    unsigned char pad2[8];
    unsigned int i38;
};

extern signed char lbl_49_bss_60;
extern StaticObj lbl_49_bss_68;
extern unsigned char lbl_49_bss_30[];
extern const float lbl_49_rodata_90[];
void fn_49_4DF8(void);
void __register_global_object(void*, void*, void*);

void* fn_49_6A08(void) {
    if (lbl_49_bss_60 == 0) {
        lbl_49_bss_68.f24 = lbl_49_rodata_90[0];
        lbl_49_bss_68.f28 = lbl_49_rodata_90[0];
        lbl_49_bss_68.f2c = lbl_49_rodata_90[0];
        lbl_49_bss_68.i38 = lbl_49_bss_68.i38 & ~31u;
        __register_global_object(&lbl_49_bss_68, (void*)fn_49_4DF8, lbl_49_bss_30);
        lbl_49_bss_60 = 1;
    }
    return &lbl_49_bss_68;
}

}
