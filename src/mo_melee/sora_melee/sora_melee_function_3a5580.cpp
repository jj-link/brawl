#pragma force_active on
extern "C" {
    void __register_global_object(void* obj, void (*dtor)(void*), void* handle);
    void fn_27_1E82E8(void*, int);
    void fn_27_1E847C(void*, int, void*);
    void fn_27_3A55FC(void*);
    extern char lbl_27_bss_8A70[];
    extern char lbl_27_bss_8A64[];
    extern char lbl_27_data_9D048[];
    void fn_27_3A5580(void);
}

extern "C" void fn_27_3A5580(void) {
    fn_27_1E82E8(lbl_27_bss_8A70, 0);
    *(char**)(lbl_27_bss_8A70 + 8) = lbl_27_data_9D048;
    *(char**)(lbl_27_bss_8A70) = lbl_27_data_9D048 + 8;
    fn_27_1E847C(lbl_27_bss_8A70, 0x2e, lbl_27_bss_8A70);
    __register_global_object(lbl_27_bss_8A70, fn_27_3A55FC, lbl_27_bss_8A64);
}

__declspec(section ".ctors") extern void* const fn_27_3A5580_ctor = (void*)fn_27_3A5580;
