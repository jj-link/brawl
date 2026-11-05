#pragma force_active on
struct GlobalBase {
    void* vtbl;
};
extern "C" {
extern char lbl_27_data_2ED10[];
extern char lbl_27_bss_4948[];
extern GlobalBase lbl_27_bss_4954;
void fn_27_1694EC(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_16952C() {
    lbl_27_bss_4954.vtbl = 0;
    lbl_27_bss_4954.vtbl = lbl_27_data_2ED10;
    __register_global_object(&lbl_27_bss_4954, fn_27_1694EC, lbl_27_bss_4948);
}
}

__declspec(section ".ctors") extern void* const fn_27_16952C_ctor = (void*)fn_27_16952C;
