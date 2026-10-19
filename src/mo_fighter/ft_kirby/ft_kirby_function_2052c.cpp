#include <stddef.h>
#pragma force_active on

extern "C" {

void fn_27_36DF54(void* ptr);
void fn_27_36DF64(void* ptr, int release);
void* __register_global_object(void* object, void* destructor, void* chain);

extern signed char lbl_96_bss_1068;
extern void* lbl_96_bss_106C;
extern unsigned char lbl_96_bss_F28[0xC];

void* fn_96_2052C() {
    if (lbl_96_bss_1068 == 0) {
        fn_27_36DF54(&lbl_96_bss_106C);
        __register_global_object(&lbl_96_bss_106C, (void*)fn_27_36DF64, lbl_96_bss_F28);
        lbl_96_bss_1068 = 1;
    }
    return &lbl_96_bss_106C;
}

}
