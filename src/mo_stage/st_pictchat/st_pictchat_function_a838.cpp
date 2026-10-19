#pragma force_active on
extern "C" {
struct StObj { unsigned char pad0[0x24]; float f24; float f28; float f2c; unsigned char pad1[8]; unsigned int w38; };
extern signed char lbl_73_bss_48;
extern StObj lbl_73_bss_50;
extern unsigned char lbl_73_bss_24[];
extern float lbl_73_rodata_88;
void* fn_73_4518(void*, int);
void __register_global_object(void*, void*, void*);

void* fn_73_A838(void) {
    if (lbl_73_bss_48 == 0) {
        float v = lbl_73_rodata_88;
        lbl_73_bss_50.f24 = v;
        lbl_73_bss_50.f28 = v;
        lbl_73_bss_50.f2c = v;
        lbl_73_bss_50.w38 = lbl_73_bss_50.w38 & ~31u;
        __register_global_object(&lbl_73_bss_50, (void*)fn_73_4518, lbl_73_bss_24);
        lbl_73_bss_48 = 1;
    }
    return &lbl_73_bss_50;
}
}
