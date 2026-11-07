#include <types.h>
#pragma force_active on
extern void *lbl_805A0F70;
extern int fn_8033891C(void);
extern int fn_803517BC(int, int);
int fn_803371DC(int arg0) {
    int base = *(int *)((char *)lbl_805A0F70 + 0x1c);
    int val;
    if (base == 0) return 0;
    val = fn_803517BC(fn_8033891C(), base + arg0 * 12);
    if (val != 0 && val != -1) {
    } else {
        val = 0;
    }
    return val;
}