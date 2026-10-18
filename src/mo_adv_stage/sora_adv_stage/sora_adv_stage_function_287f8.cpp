#pragma force_active on
struct GlobalObj13A0 {
    char pad0[0x24];
    float f24;
    float f28;
    float f2c;
    char pad1[0x8];
    unsigned int v38;
};

extern GlobalObj13A0 lbl_40_bss_13A0;
extern char lbl_40_bss_11C4[];
extern signed char lbl_40_bss_1398;
extern const float lbl_40_rodata_420;

extern "C" void fn_40_27CEC(void*);
extern "C" void* __register_global_object(void*, void*, void*);

extern "C" GlobalObj13A0* fn_40_287F8()
{
    if (!lbl_40_bss_1398) {
        lbl_40_bss_13A0.f24 = lbl_40_rodata_420;
        lbl_40_bss_13A0.f28 = lbl_40_rodata_420;
        lbl_40_bss_13A0.f2c = lbl_40_rodata_420;
        lbl_40_bss_13A0.v38 &= ~31u;
        __register_global_object(&lbl_40_bss_13A0, (void*)fn_40_27CEC, lbl_40_bss_11C4);
        lbl_40_bss_1398 = 1;
    }
    return &lbl_40_bss_13A0;
}
