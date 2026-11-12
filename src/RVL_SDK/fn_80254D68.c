#include <types.h>
#pragma force_active on
extern s8 fn_802560DC(int, void *);
extern void fn_80256858(void *, void *);
extern int fn_8024ABC4(u16, void *);

static inline void make_header(void *arg2, int arg1, int flag) {
    u8 var_r0_2;
    u8 *temp_r7;
    u8 *var_r4;
    u8 *slot;
    int temp_r3;
    u16 temp_r3_2;
    temp_r3 = *(u16 *)((u8 *)arg2 + 4) - 3;
    *(u16 *)((u8 *)arg2 + 4) = temp_r3;
    if (*(u16 *)((u8 *)arg2 + 2) > 0x7F) {
        *(u16 *)((u8 *)arg2 + 4) = (u16)temp_r3 - 1;
    }
    if (arg1 != 0) var_r0_2 = (u8)*(u16 *)((u8 *)arg2 + 6);
    else var_r0_2 = 0;
    if (var_r0_2 != 0) {
        *(u16 *)((u8 *)arg2 + 4) -= 1;
    }
    temp_r7 = (u8 *)arg2 + *(u16 *)((u8 *)arg2 + 4);
    temp_r7[8] = (u8)(flag | 1 | ((arg1 << 2) & 0x3FC));
    var_r4 = temp_r7 + 9;
    *var_r4++ = (u8)((((-(int)var_r0_2 | var_r0_2) >> 31) & 0x10) | 0xEF);
    temp_r3_2 = *(u16 *)((u8 *)arg2 + 2);
    if (temp_r3_2 <= 0x7F) {
        *var_r4++ = (u8)((temp_r3_2 << 1) | 1);
        *(u16 *)((u8 *)arg2 + 2) += 3;
    } else {
        *var_r4++ = (u8)(temp_r3_2 << 1);
        *var_r4++ = (u8)(*(u16 *)((u8 *)arg2 + 2) >> 7);
        *(u16 *)((u8 *)arg2 + 2) += 4;
    }
    if (var_r0_2 != 0) {
        *var_r4 = var_r0_2;
        *(u16 *)((u8 *)arg2 + 2) += 1;
    }
    temp_r7 = (u8 *)arg2 + *(u16 *)((u8 *)arg2 + 4);
    slot = temp_r7 + (*(u16 *)((u8 *)arg2 + 2))++;
    slot[8] = (u8)fn_802560DC(2, temp_r7 + 8);
}
void fn_80254D68(void *arg0, int arg1, void *arg2) {
    int flag;
    int v = 1;
    if (((u8 *)arg0)[0x6D] == 0) v = 0;
    flag = (v << 1) & 0xFE;
    make_header(arg2, arg1, flag);
    if (arg1 == 0) fn_80256858(arg0, arg2);
    else fn_8024ABC4(*(u16 *)((u8 *)arg0 + 0x68), arg2);
}