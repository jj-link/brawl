#pragma force_active on
extern "C" char lbl_27_bss_13F0;
extern "C" char lbl_27_bss_13F8[];
extern "C" char lbl_27_bss_F50[];
extern "C" void fn_27_13700(void*);
extern "C" void fn_27_1374C(void*, int);
extern "C" void __register_global_object(void*, void (*)(void*, int), void*);

extern "C" void* fn_27_85560() {
    if (!lbl_27_bss_13F0) {
        fn_27_13700(lbl_27_bss_13F8);
        __register_global_object(lbl_27_bss_13F8, fn_27_1374C, lbl_27_bss_F50);
        lbl_27_bss_13F0 = 1;
    }
    return lbl_27_bss_13F8;
}
