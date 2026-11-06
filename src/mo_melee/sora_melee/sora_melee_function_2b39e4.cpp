#pragma force_active on
#pragma optimize_for_size on
extern "C" {
extern char lbl_27_data_79170[0x9C];
extern void* lbl_27_bss_7164;
extern char lbl_27_bss_7158[0xC];
void fn_27_2B39A4(void*, int);
void __register_global_object(void*, void*, void*);
void fn_27_2B39E4() {
    lbl_27_bss_7164 = 0;
    lbl_27_bss_7164 = lbl_27_data_79170;
    __register_global_object(&lbl_27_bss_7164, (void*)fn_27_2B39A4, lbl_27_bss_7158);
}
}

__declspec(section ".ctors") extern void* const fn_27_2B39E4_ctor = (void*)fn_27_2B39E4;
