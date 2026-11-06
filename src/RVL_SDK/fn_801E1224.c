#include <revolution/OS/OSHardware.h>
#include <revolution/OS/OSInterrupt.h>
#include <revolution/OS/OSThread.h>
#pragma force_active on

extern void fn_801E1790(OSThreadQueue* queue);

static BOOL __OSIsThreadActive(OSThread* thread) {
    OSThread* iter;

    if (thread->state == OS_THREAD_STATE_EXITED) {
        return FALSE;
    }

    for (iter = OS_THREAD_QUEUE.head; iter != NULL; iter = iter->nextActive) {
        if (thread == iter) {
            return TRUE;
        }
    }

    return FALSE;
}

BOOL OSJoinThread(OSThread* thread, void* val) {
    BOOL enabled;
    OSThread* next;
    OSThread* prev;

    enabled = OSDisableInterrupts();

    if (!(thread->flags & OS_THREAD_DETACHED) &&
        thread->state != OS_THREAD_STATE_MORIBUND &&
        thread->joinQueue.head == NULL) {
        fn_801E1790(&thread->joinQueue);
        if (!__OSIsThreadActive(thread)) {
            OSRestoreInterrupts(enabled);
            return FALSE;
        }
    }

    if (thread->state == OS_THREAD_STATE_MORIBUND) {
        if (val != NULL) {
            *(u32*)val = thread->val;
        }

        next = thread->nextActive;
        prev = thread->prevActive;

        if (next == NULL) {
            OS_THREAD_QUEUE.tail = prev;
        } else {
            next->prevActive = prev;
        }

        if (prev == NULL) {
            OS_THREAD_QUEUE.head = next;
        } else {
            prev->nextActive = next;
        }

        thread->state = OS_THREAD_STATE_EXITED;

        OSRestoreInterrupts(enabled);
        return TRUE;
    }

    OSRestoreInterrupts(enabled);
    return FALSE;
}
