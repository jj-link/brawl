#include <types.h>
#pragma force_active on
extern "C" {
    void fn_27_197E44(void* obj);
    void* __register_global_object(void* object, void* destructor, void* chain);
}
extern "C" void* fn_27_197E54(void* p, s32 n);

extern "C" char lbl_119_bss_230;
extern "C" int lbl_119_bss_234;
extern "C" void* lbl_119_bss_224[3];

extern "C" void* fn_119_74EC(void) {
    if (!lbl_119_bss_230) {
        fn_27_197E44(&lbl_119_bss_234);
        __register_global_object(&lbl_119_bss_234, (void*)fn_27_197E54, lbl_119_bss_224);
        lbl_119_bss_230 = 1;
    }
    return &lbl_119_bss_234;
}
