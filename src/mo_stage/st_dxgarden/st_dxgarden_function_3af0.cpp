#pragma force_active on
extern "C" {
struct St77ObjB {
    char pad0[0x24];
    float f24;
    float f28;
    float f2c;
    char pad30[8];
    unsigned int f38;
};
extern signed char lbl_77_bss_B8;
extern St77ObjB lbl_77_bss_C0;
extern unsigned char lbl_77_bss_30[];
extern float lbl_77_rodata_80;
void fn_77_2560(void);
void* __register_global_object(void*, void*, void*);

void* fn_77_3AF0(void) {
    if (lbl_77_bss_B8 == 0) {
        lbl_77_bss_C0.f24 = lbl_77_rodata_80;
        lbl_77_bss_C0.f28 = lbl_77_rodata_80;
        lbl_77_bss_C0.f2c = lbl_77_rodata_80;
        lbl_77_bss_C0.f38 = lbl_77_bss_C0.f38 & ~31u;
        __register_global_object(&lbl_77_bss_C0, reinterpret_cast<void*>(fn_77_2560), lbl_77_bss_30);
        lbl_77_bss_B8 = 1;
    }
    return &lbl_77_bss_C0;
}
}
