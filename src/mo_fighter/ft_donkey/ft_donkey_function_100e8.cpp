#pragma force_active on
extern "C" void fn_92_10130(void** object);
extern "C" void* fn_92_100A8(void* ptr, int count);
extern "C" void* __register_global_object(void* object, void* destructor, void* chain);
extern "C" void* lbl_92_bss_284;
extern "C" char lbl_92_bss_278[12];

extern "C" void fn_92_100E8() {
    fn_92_10130((void**)&lbl_92_bss_284);
    __register_global_object((void*)&lbl_92_bss_284, (void*)fn_92_100A8, (void*)lbl_92_bss_278);
}

__declspec(section ".ctors") extern void* const fn_92_100E8_ctor = (void*)fn_92_100E8;
