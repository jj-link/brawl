#pragma force_active on
extern "C" unsigned char lbl_110_bss_3C4[];
extern "C" unsigned char lbl_110_bss_3B8[];
extern "C" void fn_110_198E0(void* p);
extern "C" void* fn_110_19858(void* p, short flags);
extern "C" void* __register_global_object(void* object, void* destructor, void* chain);

extern "C" {
void fn_110_19898() {
    fn_110_198E0(lbl_110_bss_3C4);
    __register_global_object(lbl_110_bss_3C4, (void*)fn_110_19858, lbl_110_bss_3B8);
}
}

__declspec(section ".ctors") extern void* const fn_110_19898_ctor = (void*)fn_110_19898;
