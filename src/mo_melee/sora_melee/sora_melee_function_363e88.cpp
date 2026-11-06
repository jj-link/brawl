#pragma force_active on
extern "C" {
struct GlobalBase {
    void* vtbl;
};
extern char lbl_27_data_90F78[];
extern char lbl_27_bss_8230[];
extern GlobalBase lbl_27_bss_823C;
void fn_27_363E48(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_363E88() {
    lbl_27_bss_823C.vtbl = 0;
    lbl_27_bss_823C.vtbl = lbl_27_data_90F78;
    __register_global_object(&lbl_27_bss_823C, fn_27_363E48, lbl_27_bss_8230);
}
}

__declspec(section ".ctors") extern void* const fn_27_363E88_ctor = (void*)fn_27_363E88;
