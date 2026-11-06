#pragma force_active on
extern "C" {
struct GlobalBase { void* vtbl; };
extern char lbl_27_data_30D78[];
extern char lbl_27_bss_4D00[];
extern GlobalBase lbl_27_bss_4D0C;
void fn_27_186768(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_1867A8() {
    lbl_27_bss_4D0C.vtbl = 0;
    lbl_27_bss_4D0C.vtbl = lbl_27_data_30D78;
    __register_global_object(&lbl_27_bss_4D0C, fn_27_186768, lbl_27_bss_4D00);
}
}

__declspec(section ".ctors") extern void* const fn_27_1867A8_ctor = (void*)fn_27_1867A8;
