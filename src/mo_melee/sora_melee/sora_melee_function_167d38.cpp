#pragma force_active on
extern "C" {
extern char lbl_27_data_2EAD0[];
extern char lbl_27_bss_48F8[];
void fn_27_167CF8(void*, int);
void __register_global_object(void*, void*, void*);

struct S {
    void* vtable;
};

extern S lbl_27_bss_4904;

void fn_27_167D38() {
    lbl_27_bss_4904.vtable = 0;
    lbl_27_bss_4904.vtable = lbl_27_data_2EAD0;
    __register_global_object(&lbl_27_bss_4904, (void*)fn_27_167CF8, lbl_27_bss_48F8);
}
}

__declspec(section ".ctors") extern void* const fn_27_167D38_ctor = (void*)fn_27_167D38;
