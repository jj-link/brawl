#include <string.h>
#pragma force_active on
extern void *lbl_805A0F70;
extern char lbl_80489460[];
extern char lbl_8048948C[];
extern int fn_80339410(void);
extern int fn_8033891C(void);
extern int fn_803517BC(int, void *);
extern int fn_803685D0(void *, int);
extern int fn_80368648(void *, int);
extern void fn_80335638(int, const char *, ...);

void fn_803369F0(void *arg0) {
    int value;
    if (lbl_805A0F70 != 0 && fn_80339410() != 0 && fn_8033891C() != 0 &&
        (value = fn_803517BC(fn_8033891C(), arg0)) != 0 && value != -1 &&
        fn_803685D0(*(void **)((char *)lbl_805A0F70 + 4), value) != 0) {
        fn_80368648(*(void **)((char *)lbl_805A0F70 + 4), value);
        fn_80335638(4, lbl_80489460);
    } else {
        fn_80335638(4, lbl_8048948C);
    }
    memset(arg0, 0, 12);
}