#pragma force_active on
extern "C" {
    void fn_27_8B574(void* self, int flag);
    void fn_27_1DC918(void* self);
    extern int lbl_27_data_45A58[];
    extern char lbl_27_bss_50B0[];
    extern char lbl_27_bss_50A0[];
    void* __register_global_object(void* object, void* destructor, void* chain);

    void fn_27_1DCB14() {
        fn_27_8B574(lbl_27_bss_50B0, 2);
        *(int*)(lbl_27_bss_50B0 + 4) = (int)lbl_27_data_45A58;
        __register_global_object(lbl_27_bss_50B0, (void*)fn_27_1DC918, lbl_27_bss_50A0);
    }
}

__declspec(section ".ctors") extern void* const fn_27_1DCB14_ctor = (void*)fn_27_1DCB14;
