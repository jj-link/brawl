#pragma force_active on
extern "C" unsigned char lbl_110_bss_374[];
extern "C" unsigned char lbl_110_bss_368[];
extern "C" void fn_110_18BA8(void* p);
extern "C" void* fn_110_18B20(void* p, short n);
extern "C" void* __register_global_object(void* object, void* (*destructor)(void*, short), void* chain);

extern "C" void fn_110_18B60(void) {
    fn_110_18BA8(lbl_110_bss_374);
    __register_global_object(lbl_110_bss_374, fn_110_18B20, lbl_110_bss_368);
}

__declspec(section ".ctors") extern void* const fn_110_18B60_ctor = (void*)fn_110_18B60;
