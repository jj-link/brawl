#pragma force_active on
extern "C" {
    void fn_27_8B574(void* self, int flag);
    void fn_27_14B548(void* self);
    extern int lbl_27_data_2BDE8[];
    extern void* lbl_27_bss_4658[];
    extern void* lbl_27_bss_4648[];
    void* __register_global_object(void* object, void* destructor, void* chain);

    void fn_27_14B5A0() {
        fn_27_8B574(lbl_27_bss_4658, 0);
        *(int*)((char*)lbl_27_bss_4658 + 4) = (int)lbl_27_data_2BDE8;
        __register_global_object(lbl_27_bss_4658, fn_27_14B548, lbl_27_bss_4648);
    }
}

__declspec(section ".ctors") extern void* const fn_27_14B5A0_ctor = (void*)fn_27_14B5A0;
