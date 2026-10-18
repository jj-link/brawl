#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct SoObj {
    u8 pad0[0x60];
    float f60;
    float f64;
    float f68;
    u8 pad6C[8];
    u32 u74;
    u8 pad78[0xA0 - 0x78];
};

extern "C" {
    extern signed char lbl_27_bss_17A8;
    extern SoObj lbl_27_bss_17B0;
    extern const float lbl_27_rodata_B74;
    extern u8 lbl_27_bss_FEC[];
    void fn_27_86D4C(void);
    void* __register_global_object(void* object, void* destructor, void* chain);

    void* fn_27_85CD8(void)
    {
        if (lbl_27_bss_17A8 == 0) {
            float c = lbl_27_rodata_B74;
            lbl_27_bss_17B0.f60 = c;
            lbl_27_bss_17B0.f64 = c;
            lbl_27_bss_17B0.f68 = c;
            lbl_27_bss_17B0.u74 = lbl_27_bss_17B0.u74 & ~31u;
            __register_global_object(&lbl_27_bss_17B0, (void*)fn_27_86D4C, lbl_27_bss_FEC);
            lbl_27_bss_17A8 = 1;
        }
        return &lbl_27_bss_17B0;
    }
}
