#pragma force_active on

extern "C" {
extern char lbl_27_data_30430[];
extern char lbl_27_bss_4BB0[0xC];
void* fn_27_17AF6C(void*, int);
void __register_global_object(void*, void*, void*);

struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_4BBC;

void fn_27_17AFAC() {
    lbl_27_bss_4BBC.vtable = 0;
    lbl_27_bss_4BBC.vtable = (void*)&lbl_27_data_30430;
    __register_global_object(&lbl_27_bss_4BBC, (void*)fn_27_17AF6C, lbl_27_bss_4BB0);
}
}

__declspec(section ".ctors") extern void* const fn_27_17AFAC_ctor = (void*)fn_27_17AFAC;
