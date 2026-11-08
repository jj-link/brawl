#include <revolution/DVD/dvd.h>
#include <revolution/OS/OSAlarm.h>
#pragma force_active on

extern unsigned int fn_801FC4B0(void);
extern void fn_801D68F8(OSAlarm*, s64, OSAlarmHandler);
extern void fn_801F6EE0(OSAlarm*, OSContext*);
extern void fn_801F7008(void);
extern void fn_801FC1C0(int, void (*)(void));
extern void fn_801F9688(void);
extern OSAlarm lbl_804E4290;
extern DVDCommandBlock *executing_805A0990;
extern DVDCommandBlock DummyCommandBlock_804E4260;
extern int FatalErrorFlag_805A090C;
extern int lbl_805A0910;
extern DVDCommandCallback lbl_805A0980;

void fn_801F6EE4(u32 arg0) {
    DVDCommandBlock *block;
    if (fn_801FC4B0()) {
        OSCreateAlarm(&lbl_804E4290);
        fn_801D68F8(&lbl_804E4290, 1, fn_801F6EE0);
        return;
    }
    executing_805A0990->state = -1;
    if (arg0 == 0x10) {
        fn_801FC1C0(0x1234568, fn_801F7008);
    } else if (arg0 == 0x20) {
        fn_801FC1C0(0x1234569, fn_801F7008);
    } else {
        FatalErrorFlag_805A090C = 1;
        block = executing_805A0990;
        executing_805A0990 = &DummyCommandBlock_804E4260;
        if (block->callback != 0)
            block->callback(-1, block);
        if (lbl_805A0910) {
            lbl_805A0910 = 0;
            if (lbl_805A0980 != 0)
                lbl_805A0980(0, block);
        }
        fn_801F9688();
    }
}