#pragma force_active on
extern "C" {
void __register_global_object(void*, void*, void*);
void* fn_27_180204(void*, int);
extern unsigned char lbl_27_data_306D0[0x40];
extern unsigned char lbl_27_bss_4C00[0xc];
extern void* lbl_27_bss_4C0C;
void fn_27_180244(void) {
    lbl_27_bss_4C0C = 0;
    lbl_27_bss_4C0C = lbl_27_data_306D0;
    __register_global_object(&lbl_27_bss_4C0C, (void*)fn_27_180204, lbl_27_bss_4C00);
}
}

__declspec(section ".ctors") extern void* const fn_27_180244_ctor = (void*)fn_27_180244;
