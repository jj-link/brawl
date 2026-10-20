#include <types.h>
#pragma force_active on

extern "C" void* __register_global_object(void* object, void* destructor, void* chain);
extern "C" void* fn_27_84598(void* p, s32 n);

extern "C" u8 lbl_27_bss_12B0[];
extern "C" u8 lbl_27_bss_12B4[];
extern "C" u8 lbl_27_bss_EF0[];

extern "C" void* fn_27_83F40() {
    if (*(s8*)lbl_27_bss_12B0 == 0) {
        *(s32*)(lbl_27_bss_12B4 + 4) = -1;
        *(s16*)(lbl_27_bss_12B4 + 8) = 0;
        *(s16*)(lbl_27_bss_12B4 + 10) = -1;
        __register_global_object(lbl_27_bss_12B4, (void*)fn_27_84598, lbl_27_bss_EF0);
        *(u8*)lbl_27_bss_12B0 = 1;
    }

    return lbl_27_bss_12B4;
}
