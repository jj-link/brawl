#pragma force_active on
struct GlobalBase {
    void* vtbl;
};
extern "C" {
extern char lbl_27_data_2EE00[];
extern char lbl_27_bss_4968[];
extern GlobalBase lbl_27_bss_4974;
void fn_27_16999C(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_1699DC() {
    lbl_27_bss_4974.vtbl = 0;
    lbl_27_bss_4974.vtbl = lbl_27_data_2EE00;
    __register_global_object(&lbl_27_bss_4974, fn_27_16999C, lbl_27_bss_4968);
}
}

__declspec(section ".ctors") extern void* const fn_27_1699DC_ctor = (void*)fn_27_1699DC;
