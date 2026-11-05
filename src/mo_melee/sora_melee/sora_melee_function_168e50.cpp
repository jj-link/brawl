#pragma force_active on
struct GlobalBase {
    void* vtbl;
};
extern "C" {
extern char lbl_27_data_2ECA0[];
extern char lbl_27_bss_4938[];
extern GlobalBase lbl_27_bss_4944;
void fn_27_168E10(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_168E50() {
    lbl_27_bss_4944.vtbl = 0;
    lbl_27_bss_4944.vtbl = lbl_27_data_2ECA0;
    __register_global_object(&lbl_27_bss_4944, fn_27_168E10, lbl_27_bss_4938);
}
}

__declspec(section ".ctors") extern void* const fn_27_168E50_ctor = (void*)fn_27_168E50;
