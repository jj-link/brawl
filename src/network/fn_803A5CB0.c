#include <revolution/OS/OSReset.h>
#pragma force_active on
extern void fn_80399FD0(void);
extern BOOL fn_803A5D70(BOOL, u32);
extern OSShutdownFunctionInfo lbl_80537620;
extern int lbl_8059FE08;
extern int lbl_805A11D0;
extern char lbl_80492448[];
extern char lbl_80492460[];
extern int fn_803A279C(const char *, void *, int *, int);
extern u32 fn_8020E18C(void);
extern void fn_8020FC18(void *);
extern void fn_801E28B8(u8);
extern u8 fn_801D6620(void);
extern void fn_803A0A48(int);

int fn_803A5CB0(void) {
    u8 state[2];
    int result = 0;
    u32 status;
    fn_80399FD0();
    lbl_80537620.func = fn_803A5D70;
    lbl_80537620.prio = 110;
    OSRegisterShutdownFunction(&lbl_80537620);
    if (lbl_8059FE08 < 0)
        result = fn_803A279C(lbl_80492448, lbl_80492460, &lbl_8059FE08, 1);
    lbl_805A11D0 = 5;
loop:
    status = fn_8020E18C();
    if (status != 2) {
        if (status == 1)
            goto loop;
        fn_8020FC18(state);
        fn_801E28B8(state[1]);
    }
    if (fn_801D6620() == 0x40)
        fn_803A0A48(1);
    return result;
}