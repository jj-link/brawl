#pragma force_active on
extern "C" {
    extern unsigned char lbl_27_bss_7B0C[4];
    extern unsigned char lbl_27_bss_7B00[12];
    void fn_27_30F7D0(void* p);
    void fn_27_30F9EC(void* p, int n);
    void* __register_global_object(void* object, void* destructor, void* chain);
    void fn_27_30FC04();
}

extern "C" void fn_27_30FC04() {
    fn_27_30F7D0(lbl_27_bss_7B0C);
    __register_global_object(lbl_27_bss_7B0C, (void*)fn_27_30F9EC, lbl_27_bss_7B00);
}

__declspec(section ".ctors") extern void* const fn_27_30FC04_ctor = (void*)fn_27_30FC04;
