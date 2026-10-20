#include <types.h>
#pragma force_active on

struct soSomething {
    u32 m_0;
    s32 m_4;
    s16 m_8;
    s16 m_a;
};

extern "C" {
extern s8 lbl_27_bss_1220;
extern soSomething lbl_27_bss_1224;
extern u8 lbl_27_bss_EA8[12];
void fn_27_84418(void* p, s32 n);
void __register_global_object(void* object, void* destructor, void* chain);

void* fn_27_83A18() {
    if (lbl_27_bss_1220 == 0) {
        lbl_27_bss_1224.m_4 = -1;
        lbl_27_bss_1224.m_8 = 0;
        lbl_27_bss_1224.m_a = -1;
        __register_global_object(&lbl_27_bss_1224, (void*)fn_27_84418, lbl_27_bss_EA8);
        lbl_27_bss_1220 = 1;
    }
    return &lbl_27_bss_1224;
}
}
