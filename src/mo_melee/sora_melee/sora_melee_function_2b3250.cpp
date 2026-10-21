#include <types.h>
#pragma force_active on

extern "C" {
extern void* __vt__10soNullable[];
extern char lbl_27_data_6E94[];
extern char lbl_27_data_790F8[];
extern char lbl_27_bss_714C[];
extern char lbl_27_bss_7140[];
void* fn_27_2B3210(void* ptr, int size);
void* __register_global_object(void* object, void* destructor, void* chain);

void fn_27_2B3250() {
    char* obj = lbl_27_bss_714C;
    *(void**)obj = __vt__10soNullable;
    *(char**)(obj + 8) = lbl_27_data_6E94;
    *(char**)obj = lbl_27_data_6E94 + 8;
    *(unsigned char*)(obj + 4) = 0;
    *(char**)(obj + 8) = lbl_27_data_790F8;
    *(char**)obj = lbl_27_data_790F8 + 8;
    __register_global_object(obj, (void*)fn_27_2B3210, lbl_27_bss_7140);
}
}

__declspec(section ".ctors") extern void* const fn_27_2B3250_ctor = (void*)fn_27_2B3250;
