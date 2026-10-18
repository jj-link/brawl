#pragma force_active on
extern "C" {
typedef struct Obj {
    unsigned char pad0[0x24];
    float f24;
    float f28;
    float f2c;
    unsigned char pad1[0x38 - 0x30];
    unsigned int m38;
    unsigned char rest[0x68 - 0x3C];
} Obj;

extern signed char lbl_57_bss_B8;
extern Obj lbl_57_bss_C0;
extern unsigned char lbl_57_bss_30[];
extern float lbl_57_rodata_274;
extern void fn_57_9800(void);
void* __register_global_object(void*, void*, void*);

Obj* fn_57_AC00(void) {
    if (lbl_57_bss_B8 == 0) {
        float f = lbl_57_rodata_274;
        lbl_57_bss_C0.f24 = f;
        lbl_57_bss_C0.f28 = f;
        lbl_57_bss_C0.f2c = f;
        lbl_57_bss_C0.m38 = lbl_57_bss_C0.m38 & 0xFFFFFFE0u;
        __register_global_object(&lbl_57_bss_C0, (void*)fn_57_9800, lbl_57_bss_30);
        lbl_57_bss_B8 = 1;
    }
    return &lbl_57_bss_C0;
}
}
