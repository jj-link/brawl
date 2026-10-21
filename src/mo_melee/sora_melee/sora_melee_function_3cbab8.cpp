#pragma force_active on
extern "C" {
extern char lbl_27_data_A3CB0[];
extern char lbl_27_bss_8CB0[];
extern char lbl_27_bss_8CA4[];
void fn_27_1E82E8(void* self, int arg);
void fn_27_1E847C(void* self, int size, void* arg);
void* fn_27_3CBB34(void* p, int del);
void __register_global_object(void* obj, void* dtor, void* handle);
}

extern "C" void fn_27_3CBAB8() {
    fn_27_1E82E8(lbl_27_bss_8CB0, 0);
    ((void**)lbl_27_bss_8CB0)[2] = lbl_27_data_A3CB0;
    ((void**)lbl_27_bss_8CB0)[0] = lbl_27_data_A3CB0 + 8;
    fn_27_1E847C(lbl_27_bss_8CB0, 0x27, lbl_27_bss_8CB0);
    __register_global_object(lbl_27_bss_8CB0, (void*)fn_27_3CBB34, lbl_27_bss_8CA4);
}

__declspec(section ".ctors") extern void* const fn_27_3CBAB8_ctor = (void*)fn_27_3CBAB8;
