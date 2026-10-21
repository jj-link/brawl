#pragma force_active on
extern "C" {
extern unsigned char lbl_104_bss_1C4;
extern unsigned char lbl_104_bss_1B8;
void fn_104_EEB8(void*);
void* fn_104_EE30(void*, short);
void* __register_global_object(void*, void*, void*);

void fn_104_EE70(void)
{
    fn_104_EEB8(&lbl_104_bss_1C4);
    __register_global_object(&lbl_104_bss_1C4,
                             reinterpret_cast<void*>(fn_104_EE30),
                             &lbl_104_bss_1B8);
}
}

__declspec(section ".ctors") extern void* const fn_104_EE70_ctor = (void*)fn_104_EE70;
