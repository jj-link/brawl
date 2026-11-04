#pragma force_active on
typedef int s32;
typedef unsigned int u32;

extern void fn_801D8690(const char *, int, const char *, ...);
extern s32 fn_801FA940(void *, s32, s32, s32, void (*)(void), s32);
extern s32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(s32);
extern void fn_801E1790(int *);
extern int lbl_805A08D8;
extern int lbl_8059EAD0;
extern char lbl_80476774[];
extern void fn_801F6918(void);

s32 DVDReadPrio(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 irq;
    s32 result;
    s32 st;
    s32 total;
    s32 *base = (s32 *)((char *)arg0);

    if (arg3 < 0 || (u32)arg3 > *(u32 *)(base + 0x34 / 4)) {
        fn_801D8690((const char *)&lbl_8059EAD0, 0x37D, lbl_80476774);
    }

    total = arg3 + arg2;
    if (total < 0 || (u32)total >= *(u32 *)(base + 0x34 / 4) + 0x20) {
        fn_801D8690((const char *)&lbl_8059EAD0, 0x383, lbl_80476774);
    }

    if (fn_801FA940(arg0, arg1, arg2, *(s32 *)((char *)arg0 + 0x30) + (arg3 >> 2), fn_801F6918, arg4) == 0) {
        return -1;
    }

    irq = OSDisableInterrupts();
    for (;;) {
        st = arg0[3];
        if (st == 0) {
            result = arg0[8];
            break;
        }
        if (st == -1) {
            result = -1;
            break;
        }
        if (st == 10) {
            result = -3;
            break;
        }
        fn_801E1790(&lbl_805A08D8);
    }
    OSRestoreInterrupts(irq);
    return result;
}