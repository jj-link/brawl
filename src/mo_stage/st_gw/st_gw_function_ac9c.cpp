#pragma force_active on
extern "C" {
extern signed char lbl_63_bss_E0;
extern unsigned char lbl_63_bss_E8[];
extern unsigned char lbl_63_bss_4C[];
extern float lbl_63_rodata_B8;
void fn_63_85F4(void);
void __register_global_object(void*, void*, void*);

void* fn_63_AC9C(void) {
    if (lbl_63_bss_E0 == 0) {
        unsigned char* p = lbl_63_bss_E8;
        *(float*)(p + 0x24) = lbl_63_rodata_B8;
        *(float*)(p + 0x28) = lbl_63_rodata_B8;
        *(float*)(p + 0x2c) = lbl_63_rodata_B8;
        *(unsigned int*)(p + 0x38) = *(unsigned int*)(p + 0x38) & ~31u;
        __register_global_object(p, (void*)fn_63_85F4, lbl_63_bss_4C);
        lbl_63_bss_E0 = 1;
    }
    return lbl_63_bss_E8;
}
}
