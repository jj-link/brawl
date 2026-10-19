#include <types.h>
#include <stddef.h>
#pragma force_active on

extern "C" {

extern char lbl_96_bss_1008;
extern void* lbl_96_bss_100C;
extern char lbl_96_bss_E98[];

void fn_27_34D904(void* p);
void* fn_27_34D914(void* p, s32 n);
void* __register_global_object(void* object, void* destructor, void* chain);

void* fn_96_1FFEC(void) {
    if (!lbl_96_bss_1008) {
        fn_27_34D904(&lbl_96_bss_100C);
        __register_global_object(&lbl_96_bss_100C, fn_27_34D914, &lbl_96_bss_E98);
        lbl_96_bss_1008 = 1;
    }
    return &lbl_96_bss_100C;
}

}
