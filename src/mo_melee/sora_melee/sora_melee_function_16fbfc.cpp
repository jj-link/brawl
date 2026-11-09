#pragma force_active on

extern "C" {
struct GlobalBase {
    void* vtbl;
};
extern char lbl_27_data_2F628[];
extern char lbl_27_bss_4A80[];
extern GlobalBase lbl_27_bss_4A8C;
void* fn_27_16FBBC(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_16FBFC() {
    lbl_27_bss_4A8C.vtbl = 0;
    lbl_27_bss_4A8C.vtbl = (void*)&lbl_27_data_2F628;
    __register_global_object(&lbl_27_bss_4A8C, (void*)fn_27_16FBBC, lbl_27_bss_4A80);
}
}

__declspec(section ".ctors") extern void* const fn_27_16FBFC_ctor = (void*)fn_27_16FBFC;
