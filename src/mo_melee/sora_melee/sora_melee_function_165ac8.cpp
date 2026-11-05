#pragma force_active on
extern "C" {
struct GlobalBase {
    void* vtbl;
};
extern char lbl_27_data_2E7B8[];
extern char lbl_27_bss_4888[];
extern GlobalBase lbl_27_bss_4894;
void fn_27_165A88(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_165AC8() {
    lbl_27_bss_4894.vtbl = 0;
    lbl_27_bss_4894.vtbl = lbl_27_data_2E7B8;
    __register_global_object(&lbl_27_bss_4894, fn_27_165A88, lbl_27_bss_4888);
}
}

__declspec(section ".ctors") extern void* const fn_27_165AC8_ctor = (void*)fn_27_165AC8;
