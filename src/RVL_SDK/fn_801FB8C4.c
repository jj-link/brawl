#include <revolution/DVD/dvd.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

int fn_801FB8C4(DVDCommandBlock* block) {
    BOOL enabled = OSDisableInterrupts();
    DVDCommandBlock* prev = block->prev;
    DVDCommandBlock* next = block->next;
    if (prev == 0 || next == 0) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    prev->next = next;
    next->prev = prev;
    OSRestoreInterrupts(enabled);
    return 1;
}
