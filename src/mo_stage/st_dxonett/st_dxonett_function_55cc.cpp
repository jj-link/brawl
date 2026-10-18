#pragma force_active on
extern "C" {
extern signed char lbl_78_bss_B8;
extern unsigned char lbl_78_bss_C0[];
extern unsigned char lbl_78_bss_30[];
extern float lbl_78_rodata_E0;
void fn_78_4070(void);
void __register_global_object(void*, void*, void*);

void* fn_78_55CC(void) {
    if (lbl_78_bss_B8 == 0) {
        float f = lbl_78_rodata_E0;
        *(float*)(lbl_78_bss_C0 + 0x24) = f;
        *(float*)(lbl_78_bss_C0 + 0x28) = f;
        *(float*)(lbl_78_bss_C0 + 0x2c) = f;
        *(unsigned int*)(lbl_78_bss_C0 + 0x38) &= ~31u;
        __register_global_object(lbl_78_bss_C0, (void*)fn_78_4070, lbl_78_bss_30);
        lbl_78_bss_B8 = 1;
    }
    return lbl_78_bss_C0;
}
}
