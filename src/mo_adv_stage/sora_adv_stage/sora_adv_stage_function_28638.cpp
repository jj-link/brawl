#pragma force_active on
extern "C" {
extern const float lbl_40_rodata_420;
extern signed char lbl_40_bss_11D8;
extern unsigned char lbl_40_bss_11E0[0xA0];
extern unsigned char lbl_40_bss_11A0[0xC];
void fn_40_1E2F8(void* obj, int flags);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" {
void* fn_40_28638() {
    if (!lbl_40_bss_11D8) {
        unsigned int v = *(unsigned int*)(lbl_40_bss_11E0 + 0x74);
        *(float*)(lbl_40_bss_11E0 + 0x60) = lbl_40_rodata_420;
        *(float*)(lbl_40_bss_11E0 + 0x64) = lbl_40_rodata_420;
        *(float*)(lbl_40_bss_11E0 + 0x68) = lbl_40_rodata_420;
        *(unsigned int*)(lbl_40_bss_11E0 + 0x74) = v & ~31u;
        __register_global_object(lbl_40_bss_11E0, (void*)fn_40_1E2F8, lbl_40_bss_11A0);
        lbl_40_bss_11D8 = 1;
    }
    return lbl_40_bss_11E0;
}
}
