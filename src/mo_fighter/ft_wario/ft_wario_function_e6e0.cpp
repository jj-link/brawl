#pragma force_active on
extern "C" {
extern int lbl_110_bss_204;
extern char lbl_110_bss_1F8[12];
void fn_110_E728(void* p);
void* fn_110_E6A0(void* p, short flag);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void fn_110_E6E0() {
    fn_110_E728(&lbl_110_bss_204);
    __register_global_object(&lbl_110_bss_204, (void*)fn_110_E6A0, lbl_110_bss_1F8);
}

__declspec(section ".ctors") extern void* const fn_110_E6E0_ctor = (void*)fn_110_E6E0;
