#pragma force_active on

struct GlobalObject {
    void* vtable;
};

extern "C" {
extern GlobalObject lbl_27_bss_4914;
extern char lbl_27_data_2EB48[];
extern char lbl_27_bss_4908[12];
void fn_27_167E8C(void*, int);
void* __register_global_object(void*, void*, void*);
void fn_27_167ECC();
}

void fn_27_167ECC() {
    lbl_27_bss_4914.vtable = 0;
    lbl_27_bss_4914.vtable = (void*)&lbl_27_data_2EB48;
    __register_global_object(&lbl_27_bss_4914, fn_27_167E8C, lbl_27_bss_4908);
}

__declspec(section ".ctors") extern void* const fn_27_167ECC_ctor = (void*)fn_27_167ECC;
