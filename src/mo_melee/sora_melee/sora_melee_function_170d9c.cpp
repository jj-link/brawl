#pragma force_active on
struct GlobalBase {
    void* vtbl;
};
extern "C" {
extern char lbl_27_data_2F710[];
extern char lbl_27_bss_4AA0[];
extern GlobalBase lbl_27_bss_4AAC;
void fn_27_170D5C(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_170D9C() {
    lbl_27_bss_4AAC.vtbl = 0;
    lbl_27_bss_4AAC.vtbl = lbl_27_data_2F710;
    __register_global_object(&lbl_27_bss_4AAC, fn_27_170D5C, lbl_27_bss_4AA0);
}
}

__declspec(section ".ctors") extern void* const fn_27_170D9C_ctor = (void*)fn_27_170D9C;
