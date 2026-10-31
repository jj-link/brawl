#include <stdio.h>
#pragma force_active on

extern void fn_801DEFD0(int*, int*);
extern int* fn_801D718C(int, int);
extern void fn_801DA4DC(int, int, int, int, int, int, int*);
extern char lbl_8059E9D4;

void fn_801DAD24(int arg0, int arg1, int* arg2) {
    int spC, sp8;
    char sp10[32];
    int count;
    int* p;
    int* buf;
    int i;

    fn_801DEFD0(&spC, &sp8);
    sprintf(sp10, &lbl_8059E9D4, arg0);

    count = 0;
    if (arg2 != 0) {
        p = arg2;
        while (*p != 0) {
            p++;
            count++;
        }
    }

    buf = fn_801D718C((count + 2) * 4, 1);
    buf[0] = (int)sp10;
    for (i = 1; i < count + 1; i++) {
        buf[i] = arg2[i - 1];
    }

    fn_801DA4DC(-1, arg1, spC, sp8, 0, count + 1, buf);
}
