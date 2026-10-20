#include <types.h>
#pragma force_active on

extern "C" void* fn_114_158FC(void* object, s16 size);
extern "C" void __register_global_object(void* obj, void* dtor, void* ctx);

extern s8 lbl_114_bss_2D8;
extern struct {
    s8 flag;
    u8 pad[3];
    void* ptr;
} lbl_114_bss_2DC;
extern u8 lbl_114_bss_260[0xC];
extern u8 lbl_114_data_91E0[0x38];
extern u8 lbl_114_data_918C[0x38];

extern "C" void* fn_114_15838(void) {
    if (lbl_114_bss_2D8 == 0) {
        lbl_114_bss_2DC.ptr = (void*)lbl_114_data_91E0;
        lbl_114_bss_2DC.flag = 1;
        lbl_114_bss_2DC.ptr = (void*)lbl_114_data_918C;
        __register_global_object(&lbl_114_bss_2DC, (void*)fn_114_158FC, lbl_114_bss_260);
        lbl_114_bss_2D8 = 1;
    }
    return &lbl_114_bss_2DC;
}
