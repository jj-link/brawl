#include <revolution/OS/OSInterrupt.h>
#pragma force_active on
extern void fn_801D7184(int);
extern void fn_801D716C(int);
extern void fn_801DAD24(int, int, int *);
extern int lbl_805A0698;
void fn_801DEF64(int arg0, int arg1) {
    int sp8;
    OSDisableInterrupts();
    fn_801D7184(0x81280000);
    fn_801D716C(0x812F0000);
    sp8 = 0;
    lbl_805A0698 = *(int *)0x80003194;
    fn_801DAD24(arg1, arg0 | 0x80000000, &sp8);
}