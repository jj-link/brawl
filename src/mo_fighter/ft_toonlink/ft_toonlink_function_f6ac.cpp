#pragma force_active on
extern "C" void fn_121_F6F4(void **ptr);
extern "C" void* fn_121_F66C(void* ptr, short count);
extern "C" void* __register_global_object(void* object, void* destructor, void* chain);

extern "C" char lbl_121_bss_16C[4];
extern "C" char lbl_121_bss_160[12];

extern "C" void fn_121_F6AC(void)
{
    fn_121_F6F4((void **)lbl_121_bss_16C);
    __register_global_object(lbl_121_bss_16C, (void *)fn_121_F66C, lbl_121_bss_160);
}

__declspec(section ".ctors") extern void* const fn_121_F6AC_ctor = (void*)fn_121_F6AC;
