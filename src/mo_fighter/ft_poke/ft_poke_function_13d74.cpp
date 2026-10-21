#pragma force_active on
extern "C" void fn_116_13DBC(void* p);
extern "C" void* fn_116_13D34(void* p, short n);
extern "C" void* __register_global_object(void* object, void* destructor, void* chain);

extern "C" char lbl_116_bss_2E4[];
extern "C" char lbl_116_bss_2D8[];

extern "C" void fn_116_13D74() {
    fn_116_13DBC(lbl_116_bss_2E4);
    __register_global_object(lbl_116_bss_2E4, (void*)fn_116_13D34, lbl_116_bss_2D8);
}

__declspec(section ".ctors") extern void* const fn_116_13D74_ctor = (void*)fn_116_13D74;
