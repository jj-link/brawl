#pragma force_active on
extern "C" {
extern int lbl_110_bss_1C4;
extern int lbl_110_bss_1B8[3];
void fn_110_DB18(void* p);
void fn_110_DA90(void* p, short flags);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void fn_110_DAD0() {
    fn_110_DB18(&lbl_110_bss_1C4);
    __register_global_object(&lbl_110_bss_1C4, (void*)fn_110_DA90, lbl_110_bss_1B8);
}

__declspec(section ".ctors") extern void* const fn_110_DAD0_ctor = (void*)fn_110_DAD0;
