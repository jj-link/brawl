#pragma force_active on
extern "C" {
extern int lbl_119_bss_264;
extern char lbl_119_bss_258[12];
void fn_119_EE14(void* object);
void* fn_119_ED8C(void* p, short flag);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void fn_119_EDCC()
{
    fn_119_EE14(&lbl_119_bss_264);
    __register_global_object(&lbl_119_bss_264, (void*)fn_119_ED8C, lbl_119_bss_258);
}

__declspec(section ".ctors") extern void* const fn_119_EDCC_ctor = (void*)fn_119_EDCC;
