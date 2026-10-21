#pragma force_active on
extern "C" {
extern void* lbl_27_bss_4A2C;
extern char lbl_27_data_2F2D0[];
extern char lbl_27_bss_4A20[];
void fn_27_16AD18(void*);
void fn_27_16E160(void*, int);
void* __register_global_object(void*, void*, void*);

void fn_27_16E1A0(void) {
    fn_27_16AD18(&lbl_27_bss_4A2C);
    lbl_27_bss_4A2C = lbl_27_data_2F2D0;
    __register_global_object(&lbl_27_bss_4A2C, (void*)fn_27_16E160, lbl_27_bss_4A20);
}
}

__declspec(section ".ctors") extern void* const fn_27_16E1A0_ctor = (void*)fn_27_16E1A0;
