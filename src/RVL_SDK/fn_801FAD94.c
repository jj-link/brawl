#include <revolution/DVD/dvd.h>
#include <revolution/OS/OSAlarm.h>
#include <revolution/OS/OSInterrupt.h>
#include <types.h>
#pragma force_active on

extern DVDCommandBlock DummyCommandBlock_804E4260;
extern DVDCommandBlock* executing_805A0990;
extern OSAlarm lbl_804E42C0;
extern s32 lbl_805A0630;
extern s32 lbl_805A0910;
extern s32 lbl_805A0914;
extern s32 lbl_805A0924;
extern s32 lbl_805A0928;
extern s32 lbl_805A092C;
extern DVDCommandCallback lbl_805A0980;

void fn_801F9688(void);
void fn_801FB8C4(DVDCommandBlock* block);

BOOL fn_801FAD94(DVDCommandBlock* block, DVDCommandCallback callback) {
    BOOL enabled = OSDisableInterrupts();

    switch (block->state) {
    case DVD_STATE_FATAL:
    case DVD_STATE_IDLE:
    case DVD_STATE_CANCELED:
        if (callback != NULL) {
            callback(DVD_RESULT_OK, block);
        }
        break;
    case DVD_STATE_BUSY:
        if (lbl_805A0910 != 0) {
            OSRestoreInterrupts(enabled);
            return FALSE;
        }
        lbl_805A0980 = callback;
        lbl_805A0910 = 1;
        if (block->command == 4 || block->command == 0x21 || block->command == 0x22 ||
            block->command == 0x29 || block->command == 0x2A || block->command == 1) {
            lbl_805A0924 = 1;
        }
        break;
    case DVD_STATE_WAITING:
        fn_801FB8C4(block);
        block->state = DVD_STATE_CANCELED;
        if (block->callback != NULL) {
            block->callback(DVD_RESULT_CANCELED, block);
        }
        if (callback != NULL) {
            callback(DVD_RESULT_OK, block);
        }
        break;
    case DVD_STATE_COVER_CLOSED:
        switch (block->command) {
        case 4:
        case 5:
        case 13:
        case 15:
        case 33:
        case 34:
        case 37:
        case 41:
        case 42:
            if (callback != NULL) {
                callback(DVD_RESULT_OK, block);
            }
            break;
        case 1:
        case 2:
            if (lbl_805A0630 != 0) {
                executing_805A0990 = &DummyCommandBlock_804E4260;
                block->state = DVD_STATE_CANCELED;
                if (block->callback != NULL) {
                    block->callback(DVD_RESULT_CANCELED, block);
                }
                if (callback != NULL) {
                    callback(DVD_RESULT_OK, block);
                }
                fn_801F9688();
                break;
            }
            /* fallthrough */
        default:
            if (lbl_805A0910 != 0) {
                OSRestoreInterrupts(enabled);
                return FALSE;
            }
            lbl_805A0980 = callback;
            lbl_805A0910 = 1;
            break;
        }
        break;
    case DVD_STATE_NO_DISK:
    case DVD_STATE_COVER_OPENED:
    case DVD_STATE_WRONG_DISK_ID:
    case DVD_STATE_7:
    case DVD_STATE_DISK_ERROR:
        if (lbl_805A092C == 0 && lbl_805A0928 == 0) {
            OSRestoreInterrupts(enabled);
            return FALSE;
        }
        if (lbl_805A0928 != 0) {
            OSCancelAlarm(&lbl_804E42C0);
            lbl_805A0928 = 0;
        }
        if (block->state == DVD_STATE_NO_DISK) {
            lbl_805A0914 = 3;
        }
        if (block->state == DVD_STATE_COVER_OPENED) {
            lbl_805A0914 = 4;
        }
        if (block->state == DVD_STATE_WRONG_DISK_ID) {
            lbl_805A0914 = 1;
        }
        if (block->state == DVD_STATE_DISK_ERROR) {
            lbl_805A0914 = 2;
        }
        if (block->state == DVD_STATE_7) {
            lbl_805A0914 = 7;
        }
        executing_805A0990 = &DummyCommandBlock_804E4260;
        block->state = DVD_STATE_CANCELED;
        if (block->callback != NULL) {
            block->callback(DVD_RESULT_CANCELED, block);
        }
        if (callback != NULL) {
            callback(DVD_RESULT_OK, block);
        }
        fn_801F9688();
        break;
    case DVD_STATE_MOTOR_STOPPED:
        executing_805A0990 = &DummyCommandBlock_804E4260;
        block->state = DVD_STATE_CANCELED;
        if (block->callback != NULL) {
            block->callback(DVD_RESULT_CANCELED, block);
        }
        if (callback != NULL) {
            callback(DVD_RESULT_OK, block);
        }
        fn_801F9688();
        break;
    }

    OSRestoreInterrupts(enabled);
    return TRUE;
}
