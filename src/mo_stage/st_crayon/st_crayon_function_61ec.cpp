#pragma force_active on
extern "C" {
extern const float lbl_56_rodata_98;
extern signed char lbl_56_bss_80;
extern unsigned char lbl_56_bss_88[];
extern unsigned char lbl_56_bss_50[];
void fn_56_36B4(void);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" {
void* fn_56_61EC() {
    if (lbl_56_bss_80 == 0) {
        float f = lbl_56_rodata_98;
        *(float*)(lbl_56_bss_88 + 0x24) = f;
        *(float*)(lbl_56_bss_88 + 0x28) = f;
        *(float*)(lbl_56_bss_88 + 0x2c) = f;
        *(unsigned int*)(lbl_56_bss_88 + 0x38) &= ~0x1fu;
        __register_global_object(lbl_56_bss_88, (void*)fn_56_36B4, lbl_56_bss_50);
        lbl_56_bss_80 = 1;
    }
    return lbl_56_bss_88;
}
}
