#include <st/module.h>
#pragma force_active on

extern "C" {
void fn_27_3521BC(void* ptr);
void fn_27_3521CC(void* ptr, int count);
void __register_global_object(void* object, void* dtor, void* chain);
void* fn_108_A290();

extern signed char lbl_108_bss_19C;
extern unsigned char lbl_108_bss_1A0[8];
extern unsigned char lbl_108_bss_188[0xC];
}

void* fn_108_A290() {
    if (!lbl_108_bss_19C) {
        fn_27_3521BC(lbl_108_bss_1A0);
        __register_global_object(lbl_108_bss_1A0, (void*)fn_27_3521CC, lbl_108_bss_188);
        lbl_108_bss_19C = 1;
    }
    return lbl_108_bss_1A0;
}
