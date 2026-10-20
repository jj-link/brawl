#include <types.h>
#pragma force_active on

extern "C" {
extern signed char lbl_27_bss_1100;
extern u8 lbl_27_bss_1104[12];
extern u8 lbl_27_bss_E18[12];
void* fn_27_84158(void* ptr, int size);
void* __register_global_object(void* object, void* destructor, void* chain);

void* fn_27_82FC8(void) {
    if (lbl_27_bss_1100 == 0) {
        ((s32*)lbl_27_bss_1104)[1] = -1;
        ((s16*)lbl_27_bss_1104)[4] = 0;
        ((s16*)lbl_27_bss_1104)[5] = -1;
        __register_global_object(lbl_27_bss_1104, (void*)fn_27_84158, lbl_27_bss_E18);
        lbl_27_bss_1100 = 1;
    }
    return lbl_27_bss_1104;
}
}
