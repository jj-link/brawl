#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_bss_7EFC[];
extern char lbl_27_bss_7EF0[];
extern char lbl_27_data_8D6B8[];
void fn_27_1E82E8(void*, int);
void fn_27_1E847C(void*, int, void*);
int __register_global_object(void*, void*, void*);
void fn_27_34CD68(void*);
}

extern "C" void fn_27_34CCEC() {
    char* obj = lbl_27_bss_7EFC;
    fn_27_1E82E8(obj, 0);
    *(char**)(obj + 8) = lbl_27_data_8D6B8;
    *(char**)(obj + 0) = lbl_27_data_8D6B8 + 8;
    fn_27_1E847C(obj, 0x6d, obj);
    __register_global_object(obj, (void*)fn_27_34CD68, lbl_27_bss_7EF0);
}

__declspec(section ".ctors") extern void* const fn_27_34CCEC_ctor = (void*)fn_27_34CCEC;
