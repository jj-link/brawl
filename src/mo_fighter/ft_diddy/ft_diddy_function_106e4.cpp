#pragma force_active on
extern "C" {
void fn_115_1072C(void **object);
void *fn_115_106A4(void *ptr, short count);
extern void *__register_global_object(void *object, void *destructor, void *chain);
extern char lbl_115_bss_2D4[];
extern char lbl_115_bss_2C8[];
}

extern "C" void fn_115_106E4()
{
    fn_115_1072C((void **)lbl_115_bss_2D4);
    __register_global_object(lbl_115_bss_2D4, (void *)fn_115_106A4, lbl_115_bss_2C8);
}

__declspec(section ".ctors") extern void* const fn_115_106E4_ctor = (void*)fn_115_106E4;
