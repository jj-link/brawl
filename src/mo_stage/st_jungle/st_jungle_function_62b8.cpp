#pragma force_active on
typedef struct {
    char pad0[0x24];
    float f24;
    float f28;
    float f2c;
    char pad1[8];
    unsigned int w38;
} S68;

extern "C" {
extern signed char lbl_51_bss_60;
extern S68 lbl_51_bss_68;
extern unsigned char lbl_51_bss_30[];
extern const float lbl_51_rodata_90;
void fn_51_49C0(void);
void __register_global_object(void*, void*, void*);
}

extern "C" void* fn_51_62B8(void)
{
    if (lbl_51_bss_60 == 0) {
        float v = lbl_51_rodata_90;
        lbl_51_bss_68.f24 = v;
        lbl_51_bss_68.f28 = v;
        lbl_51_bss_68.f2c = v;
        lbl_51_bss_68.w38 = lbl_51_bss_68.w38 & ~31u;
        __register_global_object(&lbl_51_bss_68, (void*)fn_51_49C0, lbl_51_bss_30);
        lbl_51_bss_60 = 1;
    }
    return &lbl_51_bss_68;
}
