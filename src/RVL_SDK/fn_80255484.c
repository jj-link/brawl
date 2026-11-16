#include <types.h>
#pragma force_active on

extern void *fn_8022EFF8(int);
extern s8 fn_802560DC(int, void *);
extern void fn_80256858(void *, void *);

void fn_80255484(u8 *arg0, s32 arg1, u8 arg2) {
    u8 *temp_r31;
    u8 *temp_r30;
    u16 *temp_r3;
    s32 flag;
    s32 var_r3;

    var_r3 = 1;
    if (arg0[0x6D] == 0) {
        var_r3 = 0;
    }
    flag = (var_r3 << 1) & 0xFE;
    temp_r31 = (u8 *)fn_8022EFF8(2);
    if (temp_r31 != 0) {
        temp_r30 = temp_r31 + 0x11;
        temp_r3 = (u16 *)(temp_r31 + 4);
        *temp_r3 = 9;
        *temp_r30++ = (u8)(flag | 1 | ((arg1 << 2) & 0x3FC));
        *temp_r30++ = 0xFF;
        *temp_r30++ = 1;
        *temp_r30++ = arg2;
        *temp_r30++ = (u8)fn_802560DC(2, temp_r31 + *temp_r3 + 8);
        *(u16 *)(temp_r31 + 2) = 5;
        fn_80256858((void *)arg0, (void *)temp_r31);
    }
}
