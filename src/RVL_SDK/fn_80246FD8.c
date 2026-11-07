#include <string.h>
#pragma force_active on
extern unsigned char lbl_8052C870[];
extern void fn_80247100(void);
void fn_80246FD8(void) {
    memset(lbl_8052C870, 0, 0x144);
    lbl_8052C870[0xCA] = 1;
    *(unsigned short *)(lbl_8052C870 + 0xCC) = 0x40;
    lbl_8052C870[0x106] = 1;
    *(unsigned short *)(lbl_8052C870 + 0x108) = 0x40;
    *(void (**)(void))(lbl_8052C870 + 0x2C) = fn_80247100;
    lbl_8052C870[0x141] = 0;
}