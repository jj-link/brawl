#include <types.h>
#pragma force_active on

struct GlobalObj {
    u8 flag : 1;
    u8 rest : 7;
    u8 pad1[3];
    s32 field4;
    u8 pad8[0x10];
    void *field18;
};

extern signed char lbl_27_bss_19B0;
extern GlobalObj lbl_27_bss_19B4;
extern u8 lbl_27_bss_104C[0xC];
extern u8 lbl_27_data_B310[0xC];
extern "C" void fn_27_7D898(void);
extern "C" void *__register_global_object(void *object, void *destructor, void *chain);

extern "C" {
void *fn_27_862E8(void) {
    if (!lbl_27_bss_19B0) {
        lbl_27_bss_19B4.flag = 0;
        lbl_27_bss_19B4.field18 = lbl_27_data_B310;
        lbl_27_bss_19B4.field4 = 0;
        __register_global_object(&lbl_27_bss_19B4, (void *)fn_27_7D898, lbl_27_bss_104C);
        lbl_27_bss_19B0 = 1;
    }
    return &lbl_27_bss_19B4;
}
}
