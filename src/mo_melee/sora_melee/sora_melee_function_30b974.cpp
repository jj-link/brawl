#include <types.h>
#pragma force_active on

extern "C" void fn_27_1E82E8(void*, int);
extern "C" void fn_27_1E847C(void*, int, void*);
extern "C" void __register_global_object(void*, void (*)(void*), void*);
extern "C" void fn_27_30B9F0(void*);
extern "C" unsigned char lbl_27_bss_7720[];
extern "C" unsigned char lbl_27_bss_7714[];
extern "C" unsigned char lbl_27_data_82F70[];

extern "C" void fn_27_30B974() {
    fn_27_1E82E8(lbl_27_bss_7720, 0);
    unsigned char* d = lbl_27_data_82F70;
    *(unsigned char**)(lbl_27_bss_7720 + 8) = d;
    *(unsigned char**)lbl_27_bss_7720 = d + 8;
    fn_27_1E847C(lbl_27_bss_7720, 0x3C, lbl_27_bss_7720);
    __register_global_object(lbl_27_bss_7720, (void (*)(void*))fn_27_30B9F0, lbl_27_bss_7714);
}

__declspec(section ".ctors") extern void* const fn_27_30B974_ctor = (void*)fn_27_30B974;
