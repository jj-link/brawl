#pragma force_active on
extern "C" {
void fn_104_1390C(void* p);
void* fn_104_13884(void* ptr, short count);
void* __register_global_object(void* object, void* destructor, void* chain);

extern int lbl_104_bss_2CC;
extern char lbl_104_bss_2C0[];
}

extern "C" void fn_104_138C4()
{
    fn_104_1390C(&lbl_104_bss_2CC);
    __register_global_object(&lbl_104_bss_2CC, (void*)fn_104_13884, lbl_104_bss_2C0);
}

__declspec(section ".ctors") extern void* const fn_104_138C4_ctor = (void*)fn_104_138C4;
