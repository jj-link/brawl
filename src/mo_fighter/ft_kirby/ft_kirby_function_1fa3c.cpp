#include <stddef.h>
#pragma force_active on

extern "C" {
void fn_27_2D90B0(void* self);
void fn_27_2D90C0(void* p, int n);
void* __register_global_object(void* object, void* destructor, void* chain);

extern char lbl_96_bss_FA0;
extern char lbl_96_bss_FA4[4];
extern char lbl_96_bss_DFC[12];

void* fn_96_1FA3C() {
    if ((signed char)lbl_96_bss_FA0 == 0) {
        fn_27_2D90B0(&lbl_96_bss_FA4);
        __register_global_object(&lbl_96_bss_FA4, (void*)fn_27_2D90C0, &lbl_96_bss_DFC);
        lbl_96_bss_FA0 = 1;
    }
    return &lbl_96_bss_FA4;
}
}
