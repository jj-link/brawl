#pragma force_active on
#include <revolution/DWC/dwc_init.h>
#include <revolution/OS/OS.h>
#include <string.h>

extern void fn_80335384(DWCAlloc, DWCFree);
extern void fn_80352040(int);
extern void fn_8034F020(int);
extern void fn_8034F684(void);
extern void fn_8035DFCC(void (*)(void), void (*)(void), void (*)(void), void (*)(void));
extern void fn_8033546C(void);
extern void fn_803355A4(void);
extern void fn_803354D4(void);
extern void fn_803355C8(void);
extern char lbl_80489148[];
extern char lbl_80489190[];
extern char lbl_804909D0[];
extern char lbl_80535BE0[];
extern u32 lbl_805A0F50;

s32 DWC_Init(int arg0, const char* arg1, u32 arg2, DWCAlloc arg3, DWCFree arg4) {
    OSRegisterVersion(lbl_80489148);
    fn_80335384(arg3, arg4);
    fn_80352040(arg0);
    lbl_805A0F50 = arg2;
    fn_8035DFCC(fn_8033546C, fn_803355A4, fn_803354D4, fn_803355C8);
    strcpy(lbl_80535BE0, arg1);
    if (arg0 == 0) {
        strcpy(lbl_804909D0, lbl_80489190);
    }
    fn_8034F020(1);
    fn_8034F684();
    return 0;
}
