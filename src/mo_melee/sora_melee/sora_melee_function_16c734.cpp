#pragma force_active on
extern "C" {
struct GlobalBase {
    void* vtbl;
};
extern char lbl_27_data_2F098[];
extern char lbl_27_bss_49E0[];
extern GlobalBase lbl_27_bss_49EC;
void fn_27_16C6F4(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_16C734() {
    lbl_27_bss_49EC.vtbl = 0;
    lbl_27_bss_49EC.vtbl = lbl_27_data_2F098;
    __register_global_object(&lbl_27_bss_49EC, fn_27_16C6F4, lbl_27_bss_49E0);
}
}

__declspec(section ".ctors") extern void* const fn_27_16C734_ctor = (void*)fn_27_16C734;
