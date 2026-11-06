#pragma force_active on

extern "C" {
    struct GlobalBase {
        void* vtbl;
    };
    extern char lbl_27_data_8C2E0[];
    extern char lbl_27_bss_7E70[];
    extern GlobalBase lbl_27_bss_7E7C;
    void fn_27_341754(void*, int);
    void __register_global_object(void*, void*, void*);

    void fn_27_341794() {
        lbl_27_bss_7E7C.vtbl = 0;
        lbl_27_bss_7E7C.vtbl = (void*)&lbl_27_data_8C2E0;
        __register_global_object(&lbl_27_bss_7E7C.vtbl, (void*)fn_27_341754, lbl_27_bss_7E70);
    }
}

__declspec(section ".ctors") extern void* const fn_27_341794_ctor = (void*)fn_27_341794;
