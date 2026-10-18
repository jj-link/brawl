#pragma force_active on
struct St54Obj {
    char pad0[0x24];
    float f24;
    float f28;
    float f2c;
    char pad1[0x38 - 0x30];
    unsigned int f38;
    char rest[0x68 - 0x3C];
};

extern "C" {
extern signed char lbl_54_bss_E0;
extern St54Obj lbl_54_bss_E8;
extern unsigned char lbl_54_bss_4C[];
extern float lbl_54_rodata_8C;
void fn_54_4C18(void);
void* __register_global_object(void*, void*, void*);

void* fn_54_6448(void) {
    if (lbl_54_bss_E0 == 0) {
        lbl_54_bss_E8.f24 = lbl_54_rodata_8C;
        lbl_54_bss_E8.f28 = lbl_54_rodata_8C;
        lbl_54_bss_E8.f2c = lbl_54_rodata_8C;
        lbl_54_bss_E8.f38 = lbl_54_bss_E8.f38 & ~31u;
        __register_global_object(&lbl_54_bss_E8, (void*)fn_54_4C18, lbl_54_bss_4C);
        lbl_54_bss_E0 = 1;
    }
    return &lbl_54_bss_E8;
}
}
