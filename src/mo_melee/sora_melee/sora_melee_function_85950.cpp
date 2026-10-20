#pragma force_active on
extern "C" {
extern unsigned char lbl_27_bss_15E0;
extern unsigned char lbl_27_bss_15E4[];
extern unsigned char lbl_27_bss_FA4[];
void fn_27_59FD4(void*);
void fn_27_5A09C(void*, int);
void __register_global_object(void*, void (*)(void*, int), void*);
}

extern "C" void* fn_27_85950() {
    if (!*(signed char*)&lbl_27_bss_15E0) {
        fn_27_59FD4(lbl_27_bss_15E4);
        __register_global_object(lbl_27_bss_15E4, fn_27_5A09C, lbl_27_bss_FA4);
        lbl_27_bss_15E0 = 1;
    }
    return lbl_27_bss_15E4;
}
