#pragma force_active on

extern "C" unsigned int lbl_110_bss_3A4;
extern "C" unsigned char lbl_110_bss_398[12];
extern "C" void fn_110_19568(void*);
extern "C" void* fn_110_194E0(void*, short);
extern "C" void* __register_global_object(void*, void*, void*);

extern "C" void fn_110_19520(void) {
    fn_110_19568(&lbl_110_bss_3A4);
    __register_global_object(&lbl_110_bss_3A4, (void*)fn_110_194E0, lbl_110_bss_398);
}

__declspec(section ".ctors") extern void* const fn_110_19520_ctor = (void*)fn_110_19520;
