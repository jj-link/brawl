#pragma force_active on
extern "C" void* fn_109_C45C(void* p);
extern "C" void* fn_109_C3BC(void* p, short count);
extern "C" char lbl_109_bss_144[4];
extern "C" char lbl_109_bss_138[12];
extern "C" void* __register_global_object(void* object, void* destructor, void* chain);

extern "C" void fn_109_C414(void)
{
    fn_109_C45C(lbl_109_bss_144);
    __register_global_object(lbl_109_bss_144, (void*)fn_109_C3BC, lbl_109_bss_138);
}

__declspec(section ".ctors") extern void* const fn_109_C414_ctor = (void*)fn_109_C414;
