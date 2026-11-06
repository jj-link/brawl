#pragma force_active on

extern "C" {
struct S {
    void* vtable;
};
extern char lbl_27_data_305D0[];
extern char lbl_27_bss_4BE0[0xC];
extern S lbl_27_bss_4BEC;
void fn_27_17F5A0(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_17F5E0() {
    lbl_27_bss_4BEC.vtable = 0;
    lbl_27_bss_4BEC.vtable = (void*)lbl_27_data_305D0;
    __register_global_object(&lbl_27_bss_4BEC, (void*)fn_27_17F5A0, lbl_27_bss_4BE0);
}
}

__declspec(section ".ctors") extern void* const fn_27_17F5E0_ctor = (void*)fn_27_17F5E0;
