#pragma force_active on
struct StPiratesObj {
    unsigned char pad0[0x24];
    float f24;
    float f28;
    float f2c;
    unsigned char pad1[0x38 - 0x30];
    int i38;
    unsigned char rest[0x68 - 0x3C];
};

extern "C" {
extern signed char lbl_52_bss_48;
extern StPiratesObj lbl_52_bss_50;
extern unsigned char lbl_52_bss_24[];
extern float lbl_52_rodata_12C[5];
void* fn_52_5E54(void* p, int size);
void __register_global_object(void*, void*, void*);

void* fn_52_7378(void) {
    if (lbl_52_bss_48 == 0) {
        float f = lbl_52_rodata_12C[0];
        lbl_52_bss_50.f24 = f;
        lbl_52_bss_50.f28 = f;
        lbl_52_bss_50.f2c = f;
        lbl_52_bss_50.i38 &= ~31;
        __register_global_object(&lbl_52_bss_50, reinterpret_cast<void*>(fn_52_5E54), lbl_52_bss_24);
        lbl_52_bss_48 = 1;
    }
    return &lbl_52_bss_50;
}
}
