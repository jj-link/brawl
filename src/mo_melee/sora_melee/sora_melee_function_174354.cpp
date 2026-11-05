#pragma force_active on
struct GlobalBase {
    void* vtbl;
};
extern "C" {
extern char lbl_27_data_2F868[];
extern char lbl_27_bss_4AE0[];
extern GlobalBase lbl_27_bss_4AEC;
void fn_27_174314(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_174354() {
    lbl_27_bss_4AEC.vtbl = 0;
    lbl_27_bss_4AEC.vtbl = lbl_27_data_2F868;
    __register_global_object(&lbl_27_bss_4AEC, fn_27_174314, lbl_27_bss_4AE0);
}
}

__declspec(section ".ctors") extern void* const fn_27_174354_ctor = (void*)fn_27_174354;
