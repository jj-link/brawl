#pragma force_active on
extern "C" {
extern signed char lbl_96_bss_1040;
extern int lbl_96_bss_1044;
extern char lbl_96_bss_EEC[];
void fn_27_3608AC(void* self);
void* fn_27_3608BC(void* ptr, int size);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" int* fn_96_202FC() {
    if (lbl_96_bss_1040 == 0) {
        fn_27_3608AC(&lbl_96_bss_1044);
        __register_global_object(&lbl_96_bss_1044, (void*)fn_27_3608BC, lbl_96_bss_EEC);
        lbl_96_bss_1040 = 1;
    }
    return &lbl_96_bss_1044;
}
