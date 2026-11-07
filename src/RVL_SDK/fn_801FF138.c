#include <revolution/OS/OS.h>
#pragma force_active on

extern const char *lbl_8059EB10;
extern int lbl_805A0A20;
extern void fn_801FF2BC(void);
extern void fn_80201F38(unsigned int, int);
extern void fn_802014C0(void);
extern void fn_801FF764(void);
extern void fn_80200988(void);
extern void fn_80200E80(int);

void fn_801FF138(unsigned int arg0, int arg1) {
    if (lbl_805A0A20 == 0) {
        OSRegisterVersion(lbl_8059EB10);
        fn_801FF2BC();
        fn_80201F38(arg0, arg1);
        fn_802014C0();
        fn_801FF764();
        fn_80200988();
        fn_80200E80(0);
        lbl_805A0A20 = 1;
    }
}