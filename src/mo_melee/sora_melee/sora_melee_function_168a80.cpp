#pragma force_active on
extern "C" {
extern char lbl_27_data_2EBB8[];
extern char lbl_27_bss_4918[];
void fn_27_168A40(void*, int);
void __register_global_object(void*, void*, void*);

struct S {
    void* vtable;
};

extern S lbl_27_bss_4924;

void fn_27_168A80() {
    lbl_27_bss_4924.vtable = 0;
    lbl_27_bss_4924.vtable = lbl_27_data_2EBB8;
    __register_global_object(&lbl_27_bss_4924, (void*)fn_27_168A40, lbl_27_bss_4918);
}
}

__declspec(section ".ctors") extern void* const fn_27_168A80_ctor = (void*)fn_27_168A80;
