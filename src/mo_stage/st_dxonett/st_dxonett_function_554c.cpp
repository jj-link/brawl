#pragma force_active on
extern "C" {
extern signed char lbl_78_bss_48;
extern unsigned char lbl_78_bss_50[];
extern unsigned char lbl_78_bss_24[];
extern float lbl_78_rodata_E0;
void fn_78_4070(void);
void __register_global_object(void*, void*, void*);

void* fn_78_554C(void) {
    if (lbl_78_bss_48 == 0) {
        float f = lbl_78_rodata_E0;
        *(float*)(lbl_78_bss_50 + 0x24) = f;
        *(float*)(lbl_78_bss_50 + 0x28) = f;
        *(float*)(lbl_78_bss_50 + 0x2c) = f;
        *(unsigned int*)(lbl_78_bss_50 + 0x38) &= ~31u;
        __register_global_object(lbl_78_bss_50, (void*)fn_78_4070, lbl_78_bss_24);
        lbl_78_bss_48 = 1;
    }
    return lbl_78_bss_50;
}
}
