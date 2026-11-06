#pragma force_active on
extern "C" {
extern char lbl_27_data_7E318[0x40];
void* fn_27_2EE918(void*, int);
extern char* lbl_27_bss_7504;
extern char lbl_27_bss_74F8[0xC];
void __register_global_object(void*, void*, void*);
void fn_27_2EE958() {
    lbl_27_bss_7504 = 0;
    lbl_27_bss_7504 = lbl_27_data_7E318;
    __register_global_object(&lbl_27_bss_7504, (void*)fn_27_2EE918, lbl_27_bss_74F8);
}
}

__declspec(section ".ctors") extern void* const fn_27_2EE958_ctor = (void*)fn_27_2EE958;
