#pragma force_active on
extern "C" void fn_100_DDA0(void* arg);
extern "C" void* fn_100_DD18(void* ptr, short flag);
extern "C" void* __register_global_object(void* object, void* destructor, void* chain);

extern "C" char lbl_100_bss_1D4[4];
extern "C" char lbl_100_bss_1C8[12];

extern "C" void fn_100_DD58() {
    fn_100_DDA0(lbl_100_bss_1D4);
    __register_global_object(lbl_100_bss_1D4, (void*)fn_100_DD18, lbl_100_bss_1C8);
}

__declspec(section ".ctors") extern void* const fn_100_DD58_ctor = (void*)fn_100_DD58;
