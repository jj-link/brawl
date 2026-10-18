#pragma force_active on
extern "C" {
struct Obj60 {
    char pad0[0x24];
    float a;
    float b;
    float c;
    char pad1[8];
    unsigned int d;
};

extern signed char lbl_62_bss_58;
extern Obj60 lbl_62_bss_60;
extern float lbl_62_rodata_84;
extern char lbl_62_bss_34[];
void fn_62_4948(void);
void __register_global_object(void*, void*, void*);

void* fn_62_5EDC(void) {
    if (lbl_62_bss_58 == 0) {
        unsigned int t;
        lbl_62_bss_60.a = lbl_62_rodata_84;
        t = lbl_62_bss_60.d;
        lbl_62_bss_60.b = lbl_62_rodata_84;
        lbl_62_bss_60.c = lbl_62_rodata_84;
        lbl_62_bss_60.d = t & 0xFFFFFFE0;
        __register_global_object(&lbl_62_bss_60, (void*)fn_62_4948, lbl_62_bss_34);
        lbl_62_bss_58 = 1;
    }
    return &lbl_62_bss_60;
}
}
