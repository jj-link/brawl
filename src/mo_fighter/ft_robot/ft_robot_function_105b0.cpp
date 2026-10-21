#pragma force_active on
extern "C" {
extern unsigned char lbl_120_bss_314[];
extern unsigned char lbl_120_bss_308[];
extern void fn_120_105F8(void*);
extern void* fn_120_10570(void*, short);
extern void* __register_global_object(void*, void*, void*);

void fn_120_105B0() {
    fn_120_105F8(lbl_120_bss_314);
    __register_global_object(lbl_120_bss_314, (void*)fn_120_10570, lbl_120_bss_308);
}
}

__declspec(section ".ctors") extern void* const fn_120_105B0_ctor = (void*)fn_120_105B0;
