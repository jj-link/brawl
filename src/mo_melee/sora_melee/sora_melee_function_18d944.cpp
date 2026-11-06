#pragma force_active on
extern "C" {
struct GlobalBase {
    void* vtbl;
};
extern char lbl_27_data_31C38[];
extern char lbl_27_bss_4EA0[];
extern GlobalBase lbl_27_bss_4EAC;
void fn_27_18D904(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_18D944() {
    lbl_27_bss_4EAC.vtbl = 0;
    lbl_27_bss_4EAC.vtbl = lbl_27_data_31C38;
    __register_global_object(&lbl_27_bss_4EAC, fn_27_18D904, lbl_27_bss_4EA0);
}
}

__declspec(section ".ctors") extern void* const fn_27_18D944_ctor = (void*)fn_27_18D944;
