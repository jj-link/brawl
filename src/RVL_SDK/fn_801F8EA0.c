#include <revolution/OS/OSAlarm.h>
#include <revolution/OS/OSTime.h>
#pragma force_active on

extern void fn_801F7008(void);
extern void fn_801F71FC(void);
extern void fn_801F8C50(OSAlarm *, OSContext *);
extern void fn_801FC1C0(u32, void (*)(void));
extern s64 fn_801E1B54(void);
extern void fn_801F69D8(u32, u32, u32);
extern void fn_801FDC88(void (*)(void));
extern void fn_801D68F8(OSAlarm *, s64, OSAlarmHandler);

extern OSAlarm lbl_804E4360;
extern s32 lbl_805A0914;
extern s32 lbl_805A0968;
extern u32 lbl_805A096C;
extern s32 lbl_805A0974;

void fn_801F8EA0(u32 arg0) {
    if (arg0 == 0x10) {
        fn_801FC1C0(0x01234568, fn_801F7008);
        return;
    }
    if (arg0 == 0x20) {
        fn_801FC1C0(0x01234569, fn_801F7008);
        return;
    }
    if ((arg0 & 1) != 0) {
        s64 tick = fn_801E1B54();
        lbl_805A096C = (u32)tick;
        lbl_805A0968 = (s32)((u64)tick >> 32);
        lbl_805A0974 = 0;
        lbl_805A0914 = 0;
        OSCreateAlarm(&lbl_804E4360);
        fn_801D68F8(&lbl_804E4360, (OS_BUS_CLOCK_SPEED / 4 / 1000) * 100, fn_801F8C50);
    } else {
        fn_801F69D8(0x27, 0, 0);
        fn_801FDC88(fn_801F71FC);
    }
}