#pragma force_active on
extern "C" {
extern void* lbl_115_bss_2E4;
extern unsigned char lbl_115_bss_2D8[];
void* fn_115_10C38(void*);
void* fn_115_10BB0(void*, short);
void* __register_global_object(void*, void*, void*);
}

extern "C" void fn_115_10BF0()
{
    fn_115_10C38(&lbl_115_bss_2E4);
    __register_global_object(&lbl_115_bss_2E4, (void*)fn_115_10BB0, lbl_115_bss_2D8);
}

__declspec(section ".ctors") extern void* const fn_115_10BF0_ctor = (void*)fn_115_10BF0;
