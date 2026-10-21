#include <stddef.h>
#pragma force_active on

extern "C" {
void* fn_115_11458(void* object);
void* fn_115_11360(void* ptr, int count);
void* __register_global_object(void* object, void* (*destructor)(void*, int), void* chain);
extern char lbl_115_bss_314[];
extern char lbl_115_bss_308[];
}

extern "C" void fn_115_11410() {
    fn_115_11458(lbl_115_bss_314);
    __register_global_object(lbl_115_bss_314, fn_115_11360, lbl_115_bss_308);
}

__declspec(section ".ctors") extern void* const fn_115_11410_ctor = (void*)fn_115_11410;
