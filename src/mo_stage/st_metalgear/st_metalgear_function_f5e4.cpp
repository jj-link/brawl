#pragma force_active on
extern "C" {

extern signed char lbl_71_bss_D0;
extern unsigned char lbl_71_bss_D8[0x68];
extern float lbl_71_rodata_23C[];
extern unsigned char lbl_71_bss_54[0xC];
void* fn_71_EDC8(void*, int);
void __register_global_object(void*, void*, void*);

void* fn_71_F5E4() {
    if (lbl_71_bss_D0 == 0) {
        float f = lbl_71_rodata_23C[0];
        *(float*)(lbl_71_bss_D8 + 0x24) = f;
        *(float*)(lbl_71_bss_D8 + 0x28) = f;
        *(float*)(lbl_71_bss_D8 + 0x2C) = f;
        *(unsigned int*)(lbl_71_bss_D8 + 0x38) = *(unsigned int*)(lbl_71_bss_D8 + 0x38) & ~0x1F;
        __register_global_object(lbl_71_bss_D8, reinterpret_cast<void*>(fn_71_EDC8), lbl_71_bss_54);
        lbl_71_bss_D0 = 1;
    }
    return lbl_71_bss_D8;
}

}
