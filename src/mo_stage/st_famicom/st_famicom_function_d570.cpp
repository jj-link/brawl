#pragma force_active on
extern "C" {
extern signed char lbl_68_bss_80;
extern unsigned char lbl_68_bss_88[];
extern unsigned char lbl_68_bss_68[];
extern float lbl_68_rodata_D4;
extern void fn_68_C57C();
extern void __register_global_object(void*, void*, void*);

void* fn_68_D570() {
    if (lbl_68_bss_80 == 0) {
        float value = lbl_68_rodata_D4;
        unsigned int flags = *reinterpret_cast<unsigned int*>(lbl_68_bss_88 + 0x38);
        *reinterpret_cast<float*>(lbl_68_bss_88 + 0x24) = value;
        *reinterpret_cast<float*>(lbl_68_bss_88 + 0x28) = value;
        *reinterpret_cast<float*>(lbl_68_bss_88 + 0x2C) = value;
        *reinterpret_cast<unsigned int*>(lbl_68_bss_88 + 0x38) = flags & ~31u;
        __register_global_object(lbl_68_bss_88, reinterpret_cast<void*>(fn_68_C57C), lbl_68_bss_68);
        lbl_68_bss_80 = 1;
    }
    return lbl_68_bss_88;
}
}
