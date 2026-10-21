#include <types.h>
#pragma force_active on

extern "C" {
    void __register_global_object(void* object, void* destructor, void* chain);
    void* fn_27_2C0AF0(void* p, s32 n);
    extern u32 __vt__10soNullable[];
    extern u32 __vt__15soParamAccesser[];
    extern u32 lbl_27_data_7A610[];
    extern u32 lbl_27_bss_71DC[];
    extern u32 lbl_27_bss_71D0[];
}

extern "C" void fn_27_2C0B30() {
    u32* obj = lbl_27_bss_71DC;
    obj[0] = (u32)&__vt__10soNullable;
    obj[2] = (u32)&__vt__15soParamAccesser;
    obj[0] = (u32)&__vt__15soParamAccesser + 8;
    *(u8*)(obj + 1) = 0;
    obj[2] = (u32)&lbl_27_data_7A610;
    obj[0] = (u32)&lbl_27_data_7A610 + 8;
    __register_global_object(obj, fn_27_2C0AF0, lbl_27_bss_71D0);
}

__declspec(section ".ctors") extern void* const fn_27_2C0B30_ctor = (void*)fn_27_2C0B30;
