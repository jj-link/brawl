#pragma force_active on
extern "C" {
extern signed char lbl_105_bss_260;
extern char lbl_105_bss_264[];
extern char lbl_105_bss_240[];
void fn_27_196C84(void* p);
void* fn_27_82644(void* ptr, int size);
void* __register_global_object(void* object, void* destructor, void* chain);

void* fn_105_A9F4() {
    if (!lbl_105_bss_260) {
        fn_27_196C84(lbl_105_bss_264);
        __register_global_object(lbl_105_bss_264, (void*)fn_27_82644, lbl_105_bss_240);
        lbl_105_bss_260 = 1;
    }
    return lbl_105_bss_264;
}
}
