#pragma force_active on
extern "C" {
extern unsigned int lbl_120_bss_2C4;
extern unsigned char lbl_120_bss_2B8[12];
void fn_120_EEA4(void* p);
void* fn_120_EE1C(void* p, short size);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void fn_120_EE5C(void) {
    fn_120_EEA4(&lbl_120_bss_2C4);
    __register_global_object(&lbl_120_bss_2C4, (void*)fn_120_EE1C, lbl_120_bss_2B8);
}

__declspec(section ".ctors") extern void* const fn_120_EE5C_ctor = (void*)fn_120_EE5C;
