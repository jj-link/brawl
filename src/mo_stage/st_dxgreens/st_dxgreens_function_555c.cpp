#pragma force_active on
extern "C" {
extern signed char lbl_79_bss_60;
extern unsigned char lbl_79_bss_68[];
extern unsigned char lbl_79_bss_30[];
extern float lbl_79_rodata_44;
void fn_79_31DC(void);
void __register_global_object(void*, void*, void*);

void* fn_79_555C() {
    if (lbl_79_bss_60 == 0) {
        unsigned int flags = *(unsigned int*)(lbl_79_bss_68 + 0x38);
        *(float*)(lbl_79_bss_68 + 0x24) = lbl_79_rodata_44;
        *(float*)(lbl_79_bss_68 + 0x28) = lbl_79_rodata_44;
        *(float*)(lbl_79_bss_68 + 0x2C) = lbl_79_rodata_44;
        *(unsigned int*)(lbl_79_bss_68 + 0x38) = flags & ~31u;
        __register_global_object(lbl_79_bss_68, (void*)fn_79_31DC, lbl_79_bss_30);
        lbl_79_bss_60 = 1;
    }
    return lbl_79_bss_68;
}
}
