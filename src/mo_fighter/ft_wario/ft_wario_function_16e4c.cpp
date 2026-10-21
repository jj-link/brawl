#pragma force_active on
extern "C" {
extern int lbl_110_bss_334;
extern int lbl_110_bss_328;
void fn_110_16E94(void* p);
void* fn_110_16E0C(void* p, short n);
void* __register_global_object(void* object, void* destructor, void* chain);

void fn_110_16E4C(void) {
    fn_110_16E94(&lbl_110_bss_334);
    __register_global_object(&lbl_110_bss_334, (void*)fn_110_16E0C, &lbl_110_bss_328);
}
}

__declspec(section ".ctors") extern void* const fn_110_16E4C_ctor = (void*)fn_110_16E4C;
