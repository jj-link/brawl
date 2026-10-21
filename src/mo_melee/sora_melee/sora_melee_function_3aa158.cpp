#pragma force_active on
extern "C" {
extern char lbl_27_bss_8B28[];
extern char lbl_27_bss_8B1C[];
extern char lbl_27_data_9DFD0[];
void fn_27_1E82E8(void*, int);
void fn_27_1E847C(void*, int, void*);
void __register_global_object(void*, void (*)(void*), void*);
void fn_27_3AA1D4(void*);

void fn_27_3AA158() {
    fn_27_1E82E8(lbl_27_bss_8B28, 0);
    *(void**)(lbl_27_bss_8B28 + 8) = lbl_27_data_9DFD0;
    *(void**)lbl_27_bss_8B28 = lbl_27_data_9DFD0 + 8;
    fn_27_1E847C(lbl_27_bss_8B28, 0x8c, lbl_27_bss_8B28);
    __register_global_object(lbl_27_bss_8B28, fn_27_3AA1D4, lbl_27_bss_8B1C);
}
}

__declspec(section ".ctors") extern void* const fn_27_3AA158_ctor = (void*)fn_27_3AA158;
