#pragma force_active on
extern "C" {
extern signed char lbl_105_bss_268;
extern char lbl_105_bss_26C[];
extern char lbl_105_bss_24C[];
void fn_27_345BAC(void* p);
void fn_27_345BBC(void* p, int n);
void __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void* fn_105_B02C() {
    if (!lbl_105_bss_268) {
        fn_27_345BAC(lbl_105_bss_26C);
        __register_global_object(lbl_105_bss_26C, (void*)fn_27_345BBC, lbl_105_bss_24C);
        lbl_105_bss_268 = 1;
    }
    return lbl_105_bss_26C;
}
