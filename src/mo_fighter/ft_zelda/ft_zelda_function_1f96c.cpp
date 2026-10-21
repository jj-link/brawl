#pragma force_active on
extern "C" void fn_104_1F9B4(void*);
extern "C" void* fn_104_1F92C(void*, short);
extern "C" void* __register_global_object(void*, void*, void*);

extern "C" unsigned char lbl_104_bss_518[12];
extern "C" unsigned char lbl_104_bss_524[4];

extern "C" void fn_104_1F96C()
{
    fn_104_1F9B4(lbl_104_bss_524);
    __register_global_object(
        lbl_104_bss_524,
        (void*)fn_104_1F92C,
        lbl_104_bss_518
    );
}

__declspec(section ".ctors") extern void* const fn_104_1F96C_ctor = (void*)fn_104_1F96C;
