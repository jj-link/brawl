#pragma force_active on
extern "C" {
extern signed char lbl_72_bss_60;
extern unsigned char lbl_72_bss_68[];
extern const float lbl_72_rodata_6C;
extern void fn_72_2F3C();
extern unsigned char lbl_72_bss_30[];
extern void __register_global_object(void*, void*, void*);

void* fn_72_4DE8() {
    if (lbl_72_bss_60 == 0) {
        float* p = reinterpret_cast<float*>(lbl_72_bss_68 + 0x24);
        p[0] = lbl_72_rodata_6C;
        p[1] = lbl_72_rodata_6C;
        p[2] = lbl_72_rodata_6C;
        unsigned int* q = reinterpret_cast<unsigned int*>(lbl_72_bss_68 + 0x38);
        *q &= ~31u;
        __register_global_object(
            lbl_72_bss_68,
            reinterpret_cast<void*>(fn_72_2F3C),
            lbl_72_bss_30
        );
        lbl_72_bss_60 = 1;
    }
    return lbl_72_bss_68;
}
}
