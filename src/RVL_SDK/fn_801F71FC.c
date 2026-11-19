#include <revolution/DVD/dvd.h>
#include <revolution/DVD/dvderror.h>
#include <revolution/OS/OSAlarm.h>
#pragma force_active on

BOOL OSDisableInterrupts(void);
BOOL OSRestoreInterrupts(BOOL);
u32 OSGetTick(void);

extern DVDErrorInfo lbl_804E4580;
typedef __typeof__(__DVDLayoutFormat) u32v;
extern u32v lbl_805A0900;
extern BOOL lbl_805A0910;
extern u32 lbl_805A0914;
extern BOOL lbl_805A0928;
extern BOOL lbl_805A092C;
extern u32 lbl_805A0970;
extern DVDCommandCallback lbl_805A0980;
extern DVDCommandBlock* executing_805A0990;
extern void (*lbl_805A0994)(DVDCommandBlock*);
extern DVDCommandBlock DummyCommandBlock_804E4260;
extern OSAlarm lbl_804E42C0;

void fn_801F6FF4(s32, s32);
void fn_801F7008(s32, s32);
void fn_801F7138(s32, s32);
void fn_801F7700(u32);
void fn_801F8830(u32);
void fn_801F9664(OSAlarm*, OSContext*);
u32 fn_801F7044(u32);
void fn_801F8B8C(void);
void fn_801F9688(void);
void fn_801FC1C0(u32, DVDErrorCallback);
void fn_801FD98C(BOOL, BOOL, void (*)(u32));
void fn_801FE5D0(u32, void (*)(u32));
u32 fn_801FEA38(void);

static inline void StampCommand(u32 command, u32 param1, u32 param2) {
    BOOL enabled = OSDisableInterrupts();

    if (lbl_805A0900 >= 5) {
        lbl_805A0900 = 0;
    }

    lbl_804E4580.info[lbl_805A0900].command = command;
    lbl_804E4580.info[lbl_805A0900].param1 = param1;
    lbl_804E4580.info[lbl_805A0900].param2 = param2;
    lbl_804E4580.info[lbl_805A0900].tick = OSGetTick();

    lbl_805A0900++;
    OSRestoreInterrupts(enabled);
}

static inline void StampIntType(u32 intType) {
    BOOL enabled = OSDisableInterrupts();

    if (lbl_805A0900 == 0) {
        lbl_804E4580.info[5 - 1].intType = intType;
    } else {
        lbl_804E4580.info[lbl_805A0900 - 1].intType = intType;
    }

    OSRestoreInterrupts(enabled);
}

static inline BOOL CheckCancel(u32 resume) {
    if (lbl_805A0910) {
        DVDCommandBlock* block = executing_805A0990;

        lbl_805A0914 = resume;
        lbl_805A0910 = FALSE;
        executing_805A0990 = &DummyCommandBlock_804E4260;

        block->state = 10;
        if (block->callback != NULL) {
            block->callback(-3, block);
        }

        if (lbl_805A0980 != NULL) {
            lbl_805A0980(0, block);
        }

        fn_801F9688();
        return TRUE;
    }

    return FALSE;
}

static inline void stateMotorStopped(void) {
    lbl_805A0970 = 1;

    if (lbl_805A0928 || lbl_805A092C) {
        return;
    }

    lbl_805A0928 = TRUE;

    OSCreateAlarm(&lbl_804E42C0);
    OSSetPeriodicAlarm(&lbl_804E42C0, OSGetTick(),
                       (*(u32*)0x800000F8 / 4 / 1000) * 100, fn_801F9664);
}

static inline void stateError(u32 error) {
    fn_801FC1C0(error, (DVDErrorCallback)fn_801F6FF4);
}

void fn_801F71FC(u32 intType) {
    u32 category;
    u32 diimmval;
    u32 state;
    u32 resume;

    StampIntType(intType);

    if (intType == 16) {
        fn_801FC1C0(0x01234568, (DVDErrorCallback)fn_801F7008);
        return;
    }

    if (intType == 32) {
        fn_801FC1C0(0x01234569, (DVDErrorCallback)fn_801F7008);
        return;
    }

    if (intType & 2) {
        stateError(0x01234567);
        return;
    }

    diimmval = fn_801FEA38();
    state = diimmval & 0xFF000000;
    category = fn_801F7044(diimmval);

    if (category == 1) {
        stateError(diimmval);
        return;
    }

    if (category == 2 || category == 3) {
        resume = 0;
    } else if (state == 0x01000000) {
        resume = 4;
    } else if (state == 0x02000000) {
        resume = 6;
    } else if (state == 0x03000000) {
        resume = 3;
    } else if (state == 0) {
        if (diimmval == 0x053000) {
            resume = 1;
        } else {
            resume = 5;
        }
    } else {
        resume = 5;
    }

    if (CheckCancel(resume)) {
        return;
    }

    if (category == 2) {
        fn_801FC1C0(diimmval, (DVDErrorCallback)fn_801F7138);
        return;
    }

    if (category == 3) {
        if ((diimmval & ~0xFF000000) == 0x031100) {
            StampCommand(2, executing_805A0990->offset, 0);
            fn_801FE5D0(executing_805A0990->offset, fn_801F7700);
        } else {
            lbl_805A0994(executing_805A0990);
        }
        return;
    }

    if (state == 0x01000000) {
        executing_805A0990->state = 5;
        stateMotorStopped();
        return;
    }

    if (state == 0x02000000) {
        executing_805A0990->state = 3;
        fn_801F8B8C();
        return;
    }

    if (state == 0x03000000) {
        executing_805A0990->state = 4;
        stateMotorStopped();
        return;
    }

    if (state == 0) {
        if (diimmval == 0x053000) {
            StampCommand(16, 0, 0);
            fn_801FD98C(FALSE, FALSE, fn_801F8830);
        } else {
            stateError(0x01234567);
        }
        return;
    }

    stateError(0x01234567);
}
