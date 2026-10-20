#include <types.h>
#pragma force_active on

extern "C" {
extern s8 lbl_27_bss_14D8;
extern u8 lbl_27_bss_14DC[0x44];
extern u8 lbl_27_bss_F74[0xC];
void fn_27_B15E8(void*);
void fn_27_B164C(void*, int);
void __register_global_object(void*, void (*)(void*), void*);

u8* fn_27_856F0() {
    if (lbl_27_bss_14D8 == 0) {
        fn_27_B15E8(lbl_27_bss_14DC);
        __register_global_object(lbl_27_bss_14DC, (void (*)(void*))fn_27_B164C, lbl_27_bss_F74);
        lbl_27_bss_14D8 = 1;
    }
    return lbl_27_bss_14DC;
}
}
