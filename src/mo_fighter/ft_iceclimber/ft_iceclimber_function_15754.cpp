#pragma force_active on
extern "C" {
extern unsigned char lbl_105_bss_2EC[];
extern unsigned char lbl_105_bss_2E0[];
void fn_105_1579C(void **object);
void* fn_105_15714(void* p, short n);
void* __register_global_object(void *object, void *destructor, void *chain);
}

extern "C" void fn_105_15754(void)
{
    fn_105_1579C((void **)lbl_105_bss_2EC);
    __register_global_object(lbl_105_bss_2EC, (void *)fn_105_15714, lbl_105_bss_2E0);
}

__declspec(section ".ctors") extern void* const fn_105_15754_ctor = (void*)fn_105_15754;
