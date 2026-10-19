#pragma force_active on
extern "C" {
extern signed char lbl_116_bss_4B4;
extern unsigned char lbl_116_bss_4B8[8];
extern unsigned char lbl_116_bss_4A0[0x14];
void fn_27_3725C8(void* p);
void* fn_27_3725D8(void* ptr, int count);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void* fn_116_17F48() {
    if (lbl_116_bss_4B4 == 0) {
        fn_27_3725C8(lbl_116_bss_4B8);
        __register_global_object(lbl_116_bss_4B8, (void*)fn_27_3725D8, lbl_116_bss_4A0);
        lbl_116_bss_4B4 = 1;
    }
    return lbl_116_bss_4B8;
}
