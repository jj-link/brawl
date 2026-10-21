#pragma force_active on
extern "C" unsigned char lbl_110_bss_364[];
extern "C" unsigned char lbl_110_bss_358[];
extern "C" void fn_110_18770(void* p);
extern "C" void* fn_110_186E8(void* p, short flags);
extern "C" void* __register_global_object(void* object, void* destructor, void* chain);

extern "C" void fn_110_18728(void) {
    fn_110_18770(lbl_110_bss_364);
    __register_global_object(lbl_110_bss_364, (void*)fn_110_186E8, lbl_110_bss_358);
}

__declspec(section ".ctors") extern void* const fn_110_18728_ctor = (void*)fn_110_18728;
