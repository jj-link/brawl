#pragma force_active on
extern "C" {
void fn_104_1376C(void* p);
void* fn_104_136E4(void* ptr, short count);
void* __register_global_object(void* object, void* (*destructor)(void*, short), void* chain);

extern int lbl_104_bss_2B0[3];
extern int lbl_104_bss_2BC;

void fn_104_13724(void)
{
    fn_104_1376C((void*)&lbl_104_bss_2BC);
    __register_global_object((void*)&lbl_104_bss_2BC, fn_104_136E4, (void*)lbl_104_bss_2B0);
}
}

__declspec(section ".ctors") extern void* const fn_104_13724_ctor = (void*)fn_104_13724;
