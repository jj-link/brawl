#pragma force_active on
extern "C" {
struct GlobalBase {
    void* vtbl;
};
extern char lbl_27_data_9C6D8[];
extern char lbl_27_bss_8A08[];
extern GlobalBase lbl_27_bss_8A14;
void fn_27_3A1B54(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_3A1B94() {
    lbl_27_bss_8A14.vtbl = 0;
    lbl_27_bss_8A14.vtbl = lbl_27_data_9C6D8;
    __register_global_object(&lbl_27_bss_8A14, fn_27_3A1B54, lbl_27_bss_8A08);
}
}

__declspec(section ".ctors") extern void* const fn_27_3A1B94_ctor = (void*)fn_27_3A1B94;
