#include <string.h>
#pragma force_active on
extern unsigned char lbl_8052C4C0[];
extern void fn_80244478(int);
extern void fn_80244484(int);
extern void fn_80243764(void);
void fn_80243704(void) {
    unsigned char *p = lbl_8052C4C0;
    memset(p, 0, 0x3ac);
    ((void (**)(int))p)[8] = fn_80244478;
    ((void (**)(int))p)[9] = fn_80244484;
    p[0x28] = 5;
    fn_80243764();
}