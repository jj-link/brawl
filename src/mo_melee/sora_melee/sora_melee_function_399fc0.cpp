#pragma force_active on
extern "C" {
    extern char lbl_27_bss_8938[];
    extern char lbl_27_bss_892C[];
    extern char lbl_27_data_9B4F8[];
    void fn_27_1E82E8(void* self, int arg);
    void fn_27_1E847C(void* self, int arg, void* other);
    void fn_27_39A03C(void* self);
    void __register_global_object(void* obj, void (*dtor)(void*), void* handle);
}

extern "C" void fn_27_399FC0() {
    char* obj = lbl_27_bss_8938;
    fn_27_1E82E8(obj, 0);
    *(char**)(obj + 8) = lbl_27_data_9B4F8;
    *(char**)(obj + 0) = lbl_27_data_9B4F8 + 8;
    fn_27_1E847C(obj, 0x35, obj);
    __register_global_object(obj, fn_27_39A03C, lbl_27_bss_892C);
}

__declspec(section ".ctors") extern void* const fn_27_399FC0_ctor = (void*)fn_27_399FC0;
