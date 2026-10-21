#pragma force_active on
extern "C" {
void* fn_115_F9E0(void* object);
void* fn_115_F958(void* ptr, short flag);
void* __register_global_object(void* object, void* (*destructor)(void*, short), void* chain);
extern unsigned char lbl_115_bss_2C4[];
extern unsigned char lbl_115_bss_2B8[];
}

extern "C" void fn_115_F998(void) {
    fn_115_F9E0(lbl_115_bss_2C4);
    __register_global_object(lbl_115_bss_2C4, fn_115_F958, lbl_115_bss_2B8);
}

__declspec(section ".ctors") extern void* const fn_115_F998_ctor = (void*)fn_115_F998;
