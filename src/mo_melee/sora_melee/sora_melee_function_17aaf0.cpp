#pragma force_active on

extern "C" {
extern char lbl_27_data_30350[];
extern char lbl_27_bss_4B90[];
void fn_27_17AAB0(void*, int);
void __register_global_object(void*, void (*)(void*, int), void*);

struct GlobalBase {
    void* vtbl;
};

extern GlobalBase lbl_27_bss_4B9C;

void fn_27_17AAF0() {
    lbl_27_bss_4B9C.vtbl = 0;
    lbl_27_bss_4B9C.vtbl = lbl_27_data_30350;
    __register_global_object(&lbl_27_bss_4B9C, fn_27_17AAB0, lbl_27_bss_4B90);
}
}

__declspec(section ".ctors") extern void* const fn_27_17AAF0_ctor = (void*)fn_27_17AAF0;
