#pragma force_active on
extern "C" {
extern unsigned char lbl_107_bss_1AC[];
extern unsigned char lbl_107_bss_1A0[];
void fn_107_128F8(void*);
void* fn_107_12870(void*, short);
void* __register_global_object(void*, void*, void*);
}

extern "C" void fn_107_128B0()
{
    fn_107_128F8(lbl_107_bss_1AC);
    __register_global_object(lbl_107_bss_1AC,
                             (void*)fn_107_12870,
                             lbl_107_bss_1A0);
}

__declspec(section ".ctors") extern void* const fn_107_128B0_ctor = (void*)fn_107_128B0;
