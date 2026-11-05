#pragma force_active on

extern "C" {
extern char lbl_27_data_2EA60[];
extern char lbl_27_bss_48E8[];
void fn_27_167778(void*, int);
void __register_global_object(void*, void*, void*);

struct S {
    void* vtable;
};

extern S lbl_27_bss_48F4;

void fn_27_1677B8() {
    lbl_27_bss_48F4.vtable = 0;
    lbl_27_bss_48F4.vtable = lbl_27_data_2EA60;
    __register_global_object(&lbl_27_bss_48F4, (void*)fn_27_167778, lbl_27_bss_48E8);
}
}

__declspec(section ".ctors") extern void* const fn_27_1677B8_ctor = (void*)fn_27_1677B8;
