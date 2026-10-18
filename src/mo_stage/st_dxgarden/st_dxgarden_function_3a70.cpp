#pragma force_active on
extern "C" {
struct St77Obj {
    char pad0[0x24];
    float f24;
    float f28;
    float f2c;
    char pad30[8];
    unsigned int f38;
};
extern signed char lbl_77_bss_48;
extern St77Obj lbl_77_bss_50;
extern unsigned char lbl_77_bss_24[];
extern float lbl_77_rodata_80;
void fn_77_2560(void);
void* __register_global_object(void*, void*, void*);

void* fn_77_3A70(void) {
    if (lbl_77_bss_48 == 0) {
        lbl_77_bss_50.f24 = lbl_77_rodata_80;
        lbl_77_bss_50.f28 = lbl_77_rodata_80;
        lbl_77_bss_50.f2c = lbl_77_rodata_80;
        lbl_77_bss_50.f38 = lbl_77_bss_50.f38 & ~31u;
        __register_global_object(&lbl_77_bss_50, reinterpret_cast<void*>(fn_77_2560), lbl_77_bss_24);
        lbl_77_bss_48 = 1;
    }
    return &lbl_77_bss_50;
}
}
