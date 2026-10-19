#include <types.h>
#pragma force_active on

extern "C" {
extern u8 lbl_96_bss_10A0;
extern u8 lbl_96_bss_10A4[4];
extern u8 lbl_96_bss_F7C[12];
void fn_27_3C7CC4(void* p);
void* fn_27_3C7CD4(void* p, s32 n);
void* __register_global_object(void* object, void* destructor, void* chain);

void* fn_96_2083C() {
    if ((s8)lbl_96_bss_10A0 == 0) {
        fn_27_3C7CC4(lbl_96_bss_10A4);
        __register_global_object(lbl_96_bss_10A4, (void*)fn_27_3C7CD4, lbl_96_bss_F7C);
        lbl_96_bss_10A0 = 1;
    }
    return lbl_96_bss_10A4;
}
}
