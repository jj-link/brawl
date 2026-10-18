#pragma force_active on
extern "C" {
extern signed char lbl_63_bss_70;
extern unsigned char lbl_63_bss_78[];
extern unsigned char lbl_63_bss_40[];
extern float lbl_63_rodata_B8;
void fn_63_85F4(void);
void __register_global_object(void*, void*, void*);

void* fn_63_AC1C(void) {
    if (lbl_63_bss_70 == 0) {
        float f = lbl_63_rodata_B8;
        unsigned int v = *(unsigned int*)(lbl_63_bss_78 + 0x38);
        *(float*)(lbl_63_bss_78 + 0x24) = f;
        *(float*)(lbl_63_bss_78 + 0x28) = f;
        *(float*)(lbl_63_bss_78 + 0x2C) = f;
        *(unsigned int*)(lbl_63_bss_78 + 0x38) = v & ~31u;
        __register_global_object(lbl_63_bss_78, (void*)fn_63_85F4, lbl_63_bss_40);
        lbl_63_bss_70 = 1;
    }
    return lbl_63_bss_78;
}
}
