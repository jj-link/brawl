#include <types.h>
#pragma force_active on

extern "C" {
extern s8 lbl_27_bss_10E8;
extern u8 lbl_27_bss_10EC[12];
extern u8 lbl_27_bss_E0C[12];
void* fn_27_84118(void* ptr, int size);
void* __register_global_object(void* object, void* destructor, void* chain);

void* fn_27_82EEC() {
    if (!lbl_27_bss_10E8) {
        s16* p = (s16*)(lbl_27_bss_10EC + 8);
        *(s32*)(lbl_27_bss_10EC + 4) = -1;
        p[0] = 0;
        p[1] = -1;
        __register_global_object(lbl_27_bss_10EC, (void*)fn_27_84118, lbl_27_bss_E0C);
        lbl_27_bss_10E8 = 1;
    }
    return lbl_27_bss_10EC;
}
}
