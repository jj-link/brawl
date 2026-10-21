#pragma force_active on
extern "C" {
void fn_105_15BB4(void* object);
void* fn_105_15B2C(void* ptr, short count);
extern char lbl_105_bss_2FC[];
extern char lbl_105_bss_2F0[];
void* __register_global_object(void* object, void* (*destructor)(void*, short), void* chain);
}

extern "C" void fn_105_15B6C()
{
    fn_105_15BB4(lbl_105_bss_2FC);
    __register_global_object(lbl_105_bss_2FC, fn_105_15B2C, lbl_105_bss_2F0);
}

__declspec(section ".ctors") extern void* const fn_105_15B6C_ctor = (void*)fn_105_15B6C;
