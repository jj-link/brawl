#pragma force_active on
extern "C" {
void fn_27_16AD18(void* p);
void fn_27_16C890(void* p, int n);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern unsigned char lbl_27_data_2F118[0x50];
extern unsigned char lbl_27_bss_49F0[0xC];
extern void* lbl_27_bss_49FC;

extern "C" void fn_27_16C8D0() {
    fn_27_16AD18(&lbl_27_bss_49FC);
    lbl_27_bss_49FC = lbl_27_data_2F118;
    __register_global_object(&lbl_27_bss_49FC, (void*)fn_27_16C890, lbl_27_bss_49F0);
}

__declspec(section ".ctors") extern void* const fn_27_16C8D0_ctor = (void*)fn_27_16C8D0;
