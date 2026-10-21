#pragma force_active on
extern "C" {
void* fn_110_E250(void* p, short flags);
void fn_110_E2D8(void* p);
void* __register_global_object(void* object, void* destructor, void* chain);
extern char lbl_110_bss_1E8[];
extern char lbl_110_bss_1F4[];
}

extern "C" void fn_110_E290() {
    fn_110_E2D8(lbl_110_bss_1F4);
    __register_global_object(lbl_110_bss_1F4, (void*)fn_110_E250, lbl_110_bss_1E8);
}

__declspec(section ".ctors") extern void* const fn_110_E290_ctor = (void*)fn_110_E290;
