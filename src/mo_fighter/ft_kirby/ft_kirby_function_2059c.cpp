#include <stddef.h>
#pragma force_active on

extern "C" {
void fn_27_395984(void*);
void fn_27_395994(void*, int);
void* __register_global_object(void* obj, void* dtor, void* chain);

void* fn_96_2059C();
}

extern unsigned char lbl_96_bss_1070;
extern char lbl_96_bss_1074;
extern unsigned char lbl_96_bss_F34[12];

void* fn_96_2059C() {
    if ((signed char)lbl_96_bss_1070 == 0) {
        fn_27_395984(&lbl_96_bss_1074);
        __register_global_object(&lbl_96_bss_1074, (void*)fn_27_395994, lbl_96_bss_F34);
        lbl_96_bss_1070 = 1;
    }
    return &lbl_96_bss_1074;
}
