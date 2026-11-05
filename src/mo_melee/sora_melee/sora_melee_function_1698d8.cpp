#pragma force_active on
struct GlobalBase {
    void* vtbl;
};
extern "C" {
extern char lbl_27_data_2ED88[];
extern char lbl_27_bss_4958[];
extern GlobalBase lbl_27_bss_4964;
void fn_27_169898(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_1698D8() {
    lbl_27_bss_4964.vtbl = 0;
    lbl_27_bss_4964.vtbl = lbl_27_data_2ED88;
    __register_global_object(&lbl_27_bss_4964, fn_27_169898, lbl_27_bss_4958);
}
}

__declspec(section ".ctors") extern void* const fn_27_1698D8_ctor = (void*)fn_27_1698D8;
