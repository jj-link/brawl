#pragma force_active on
extern "C" {
extern void* lbl_27_bss_4A0C;
extern void* lbl_27_bss_4A00[3];
extern void* lbl_27_data_2F1A8[20];
void fn_27_16AD18(void* p);
void* fn_27_16D814(void* p, int n);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void fn_27_16D854() {
    fn_27_16AD18(&lbl_27_bss_4A0C);
    lbl_27_bss_4A0C = lbl_27_data_2F1A8;
    __register_global_object(&lbl_27_bss_4A0C, (void*)fn_27_16D814, lbl_27_bss_4A00);
}

__declspec(section ".ctors") extern void* const fn_27_16D854_ctor = (void*)fn_27_16D854;
