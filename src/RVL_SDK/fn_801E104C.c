#include <revolution/OS/OSThread.h>
#include <revolution/OS/OSMutex.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

extern int lbl_805A06F4;
extern void fn_801E07D8(OSThread*);
extern OSThread* fn_801E087C(OSThread*, int);
extern void fn_801D81F4(void*);
extern void fn_801DED58(OSThread*);
extern void fn_801E187C(void*);
extern void fn_801E0A80(int);

void OSCancelThread(OSThread* thread) {
    BOOL enabled;
    OSMutex *mutex;
    OSThread *next, *prev, *owner, *waiting;
    int priority;
    enabled = OSDisableInterrupts();
    switch (thread->state) {
    case 1:
        if (thread->suspend <= 0)
            fn_801E07D8(thread);
        break;
    case 2:
        lbl_805A06F4 = 1;
        break;
    case 4:
        next = thread->next;
        prev = thread->prev;
        if (next == 0)
            thread->queue->tail = prev;
        else
            next->prev = prev;
        if (prev == 0)
            thread->queue->head = next;
        else
            prev->next = next;
        thread->queue = 0;
        if (thread->suspend <= 0 && thread->mutex != 0) {
            owner = thread->mutex->thread;
            do {
                if (owner->suspend > 0)
                    break;
                priority = owner->base;
                for (mutex = owner->mutexQueue.head; mutex != 0; mutex = mutex->next) {
                    waiting = mutex->queue.head;
                    if (waiting != 0 && waiting->priority < priority)
                        priority = waiting->priority;
                }
                if (owner->priority == priority)
                    break;
                owner = fn_801E087C(owner, priority);
            } while (owner != 0);
        }
        break;
    default:
        OSRestoreInterrupts(enabled);
        return;
    }
    fn_801D81F4(thread);
    if (thread->flags & 1) {
        next = thread->nextActive;
        prev = thread->prevActive;
        if (next == 0)
            *(OSThread**)0x800000E0 = prev;
        else
            next->prevActive = prev;
        if (prev == 0)
            *(OSThread**)0x800000DC = next;
        else
            prev->nextActive = next;
        thread->state = 0;
    } else {
        thread->state = 8;
    }
    fn_801DED58(thread);
    fn_801E187C(&thread->joinQueue);
    if (lbl_805A06F4)
        fn_801E0A80(0);
    OSRestoreInterrupts(enabled);
}
