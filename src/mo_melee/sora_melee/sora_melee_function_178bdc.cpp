#pragma force_active on
extern "C" {
extern void* lbl_27_bss_4AFC;
extern char lbl_27_bss_4AF0[0xC];
extern char lbl_27_data_2FE90[0x40];
void fn_27_178B9C(void*, int);
void __register_global_object(void*, void*, void*);
}
extern "C" void fn_27_178BDC() {
    lbl_27_bss_4AFC = 0;
    lbl_27_bss_4AFC = lbl_27_data_2FE90;
    __register_global_object(&lbl_27_bss_4AFC, (void*)fn_27_178B9C, lbl_27_bss_4AF0);
}

__declspec(section ".ctors") extern void* const fn_27_178BDC_ctor = (void*)fn_27_178BDC;
