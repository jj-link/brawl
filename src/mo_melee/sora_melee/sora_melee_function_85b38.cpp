#include <types.h>
#pragma force_active on

extern "C" {
extern signed char lbl_27_bss_16A0;
extern u8 lbl_27_bss_16A4[0x2C];
extern u8 lbl_27_bss_FC8[0xC];
void fn_27_9FA44(void*);
void fn_27_9FA50(void*, int);
void __register_global_object(void*, void*, void*);

void* fn_27_85B38() {
    if (!lbl_27_bss_16A0) {
        fn_27_9FA44(lbl_27_bss_16A4);
        __register_global_object(lbl_27_bss_16A4, (void*)fn_27_9FA50, lbl_27_bss_FC8);
        lbl_27_bss_16A0 = 1;
    }
    return lbl_27_bss_16A4;
}
}
