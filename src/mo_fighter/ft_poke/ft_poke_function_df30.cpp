#pragma force_active on
extern "C" {
extern unsigned char lbl_116_bss_16C;
extern unsigned char lbl_116_bss_160;
void fn_116_DF78(void*);
void* fn_116_DEEC(void*, short);
void* __register_global_object(void*, void*, void*);
}

extern "C" void fn_116_DF30() {
    fn_116_DF78(&lbl_116_bss_16C);
    __register_global_object(&lbl_116_bss_16C, (void*)fn_116_DEEC, &lbl_116_bss_160);
}

__declspec(section ".ctors") extern void* const fn_116_DF30_ctor = (void*)fn_116_DF30;
