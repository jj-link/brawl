#pragma force_active on

extern "C" {
extern char lbl_27_data_8A998[];
extern char lbl_27_bss_7DC8[12];
void fn_27_3396EC(void*, int);
void __register_global_object(void*, void*, void*);
}

struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_7DD4;

extern "C" void fn_27_33972C(void) {
    lbl_27_bss_7DD4.vtable = 0;
    lbl_27_bss_7DD4.vtable = (void*)&lbl_27_data_8A998;
    __register_global_object(&lbl_27_bss_7DD4, (void*)fn_27_3396EC, lbl_27_bss_7DC8);
}

__declspec(section ".ctors") extern void* const fn_27_33972C_ctor = (void*)fn_27_33972C;
