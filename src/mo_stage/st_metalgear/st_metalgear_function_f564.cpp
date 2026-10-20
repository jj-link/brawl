#pragma force_active on
extern "C" {
extern signed char lbl_71_bss_60;
extern unsigned char lbl_71_bss_68[];
extern unsigned char lbl_71_bss_48[];
extern float lbl_71_rodata_23C[];
void* fn_71_EDC8(void*, int);
void __register_global_object(void*, void*, void*);

void* fn_71_F564() {
    if (lbl_71_bss_60 == 0) {
        unsigned char* obj = lbl_71_bss_68;
        float f = lbl_71_rodata_23C[0];
        *(float*)(obj + 0x24) = f;
        *(float*)(obj + 0x28) = f;
        *(float*)(obj + 0x2c) = f;
        *(unsigned int*)(obj + 0x38) = *(unsigned int*)(obj + 0x38) & ~31u;
        __register_global_object(obj, (void*)fn_71_EDC8, lbl_71_bss_48);
        lbl_71_bss_60 = 1;
    }
    return lbl_71_bss_68;
}
}
