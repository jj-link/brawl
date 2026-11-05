#pragma force_active on
extern "C" {
extern char lbl_27_bss_4934[];
extern char lbl_27_data_2EC28[];
extern char lbl_27_bss_4928[];
void fn_27_168B9C(void*, int);
void __register_global_object(void*, void*, void*);

struct S {
    void* vtable;
};

void fn_27_168BDC() {
    (*(S*)&lbl_27_bss_4934).vtable = 0;
    (*(S*)&lbl_27_bss_4934).vtable = (void*)lbl_27_data_2EC28;
    __register_global_object(&lbl_27_bss_4934, (void*)fn_27_168B9C, lbl_27_bss_4928);
}
}

__declspec(section ".ctors") extern void* const fn_27_168BDC_ctor = (void*)fn_27_168BDC;
