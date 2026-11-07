#include <types.h>
#pragma force_active on
extern u8 lbl_80529918[];
extern u8 *lbl_8040D8F8[];
extern void (*lbl_8040D840[])(u16 *);
s32 fn_80235004(u16 *arg0) {
    u8 *table;
    s32 i = 0;
    table = lbl_8040D8F8[*(u16 *)(lbl_80529918 + 0x18)];
    *(u16 *)(lbl_80529918 + 0x18) = *((u8)*arg0 * 3 + table + 2);
    do {
        u8 value = *((u8)*arg0 * 3 + (u8 *)(i + (u32)table));
        if (value == 0x12) break;
        lbl_8040D840[value](arg0);
        i++;
    } while (i < 2);
    return 1;
}
