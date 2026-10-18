#pragma force_active on
extern "C" {
extern signed char lbl_51_bss_D0;
extern unsigned char lbl_51_bss_D8[];
extern unsigned char lbl_51_bss_3C[];
extern float lbl_51_rodata_90;
void fn_51_49C0(void*, short);
void __register_global_object(void*, void*, void*);

void* fn_51_6338(void) {
    unsigned char* p;
    unsigned int v;
    if (lbl_51_bss_D0 == 0) {
        p = lbl_51_bss_D8;
        v = *(unsigned int*)(p + 0x38);
        *(float*)(p + 0x24) = lbl_51_rodata_90;
        v = v & ~31u;
        *(float*)(p + 0x28) = lbl_51_rodata_90;
        *(float*)(p + 0x2c) = lbl_51_rodata_90;
        *(unsigned int*)(p + 0x38) = v;
        __register_global_object(lbl_51_bss_D8, reinterpret_cast<void*>(fn_51_49C0), lbl_51_bss_3C);
        lbl_51_bss_D0 = 1;
    }
    return lbl_51_bss_D8;
}
}
