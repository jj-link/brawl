#pragma force_active on
extern "C" {
extern char lbl_105_bss_2CC[];
extern char lbl_105_bss_2C0[];
void fn_105_14BD8(void *module);
void* fn_105_14B50(void *ptr, short count);
void* __register_global_object(void *object, void *destructor, void *chain);

void fn_105_14B90(void)
{
    fn_105_14BD8(lbl_105_bss_2CC);
    __register_global_object(lbl_105_bss_2CC, (void *)fn_105_14B50, lbl_105_bss_2C0);
}
}

__declspec(section ".ctors") extern void* const fn_105_14B90_ctor = (void*)fn_105_14B90;
