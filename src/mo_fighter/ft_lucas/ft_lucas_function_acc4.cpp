#include <types.h>
#pragma force_active on

extern "C" void fn_27_197E44(void* object);
extern "C" void fn_27_197E54(void* object, short deleting);
extern "C" int __register_global_object(void* object, void* destructor, void* handle);

extern "C" signed char lbl_114_bss_1BC;
extern "C" u32 lbl_114_bss_1C0;
extern "C" signed char lbl_114_bss_1A4[12];

extern "C" void* fn_114_ACC4(void) {
    if (lbl_114_bss_1BC == 0) {
        fn_27_197E44(&lbl_114_bss_1C0);
        __register_global_object(&lbl_114_bss_1C0, (void*)fn_27_197E54, lbl_114_bss_1A4);
        lbl_114_bss_1BC = 1;
    }
    return &lbl_114_bss_1C0;
}
