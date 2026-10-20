#include <types.h>
#pragma force_active on

extern "C" {
extern s8 lbl_27_bss_13C0;
extern u8 lbl_27_bss_13C4[0x2C];
extern u8 lbl_27_bss_F44[0xC];

void* fn_27_137B4(void* self);
void fn_27_137EC(void* self, int flag);
void __register_global_object(void* obj, void* dtor, void* handle);

void* fn_27_854B0() {
    if (lbl_27_bss_13C0 == 0) {
        fn_27_137B4(lbl_27_bss_13C4);
        __register_global_object(lbl_27_bss_13C4, (void*)fn_27_137EC, lbl_27_bss_F44);
        lbl_27_bss_13C0 = 1;
    }
    return lbl_27_bss_13C4;
}
}
