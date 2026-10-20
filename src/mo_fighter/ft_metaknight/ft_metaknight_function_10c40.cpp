#include <types.h>
#pragma force_active on

extern "C" void* fn_111_10D04(void* object, s16 deleting);
extern "C" void __register_global_object(void* object, void* destructor, void* context);

extern s8 lbl_111_bss_21C;
extern u8 lbl_111_bss_220[8];
extern u8 lbl_111_bss_1C8[0xC];
extern u8 lbl_111_data_685C[];
extern u8 lbl_111_data_6808[];

extern "C" void* fn_111_10C40() {
    if (!lbl_111_bss_21C) {
        *(void**)(lbl_111_bss_220 + 4) = (void*)lbl_111_data_685C;
        lbl_111_bss_220[0] = 1;
        *(void**)(lbl_111_bss_220 + 4) = (void*)lbl_111_data_6808;
        __register_global_object((void*)lbl_111_bss_220, fn_111_10D04, (void*)lbl_111_bss_1C8);
        lbl_111_bss_21C = 1;
    }
    return (void*)lbl_111_bss_220;
}
