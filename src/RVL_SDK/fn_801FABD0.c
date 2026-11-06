#include <revolution/DVD/dvd.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

extern DVDCommandBlock* executing_805A0990;
extern DVDCommandBlock lbl_804E4390;
extern DVDCommandBlock* fn_801FB864(void);

s32 DVDGetCommandBlockStatus(const DVDCommandBlock* block) {
    s32 state;
    DVDCommandBlock* next;
    BOOL enabled = OSDisableInterrupts();

    if (block->state == DVD_STATE_COVER_CLOSED) {
        state = DVD_STATE_BUSY;
    } else if (block->state == DVD_STATE_COVER_OPENED) {
        state = DVD_STATE_NO_DISK;
    } else if (executing_805A0990 == &lbl_804E4390) {
        next = fn_801FB864();
        if (next != NULL) {
            if (block == next) {
                state = DVD_STATE_BUSY;
            } else {
                state = block->state;
            }
        } else if (block == &lbl_804E4390) {
            state = DVD_STATE_IDLE;
        } else {
            state = block->state;
        }
    } else {
        state = block->state;
    }
    OSRestoreInterrupts(enabled);
    return state;
}
