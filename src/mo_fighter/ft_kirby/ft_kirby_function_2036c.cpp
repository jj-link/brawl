#include <stddef.h>
#pragma force_active on

extern "C" {
void fn_27_361264(void* obj);
void* fn_27_361274(void* slot, int destroy);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" char lbl_96_bss_1048;
extern "C" void* lbl_96_bss_104C;
extern "C" void* lbl_96_bss_EF8[3];

extern "C" void* fn_96_2036C() {
    if (lbl_96_bss_1048 == 0) {
        fn_27_361264(&lbl_96_bss_104C);
        __register_global_object(&lbl_96_bss_104C, (void*)fn_27_361274, lbl_96_bss_EF8);
        lbl_96_bss_1048 = 1;
    }
    return &lbl_96_bss_104C;
}
