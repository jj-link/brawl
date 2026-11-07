#include <revolution/OS/OSThread.h>
#include <revolution/OS/OSMutex.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

extern int lbl_805A06F4;
extern OSThread* fn_801E087C(OSThread*, int);
extern void fn_801E0A80(int);

BOOL fn_801E1970(OSThread* thread, int prio) {
    BOOL enabled;
    OSMutex* mutex;
    OSThread* waiting;
    int priority;
    if (prio < 0 || prio > 31)
        return 0;
    enabled = OSDisableInterrupts();
    if (thread->base != prio) {
        thread->base = prio;
        do {
            if (thread->suspend > 0)
                break;
            priority = thread->base;
            for (mutex = thread->mutexQueue.head; mutex != 0; mutex = mutex->next) {
                waiting = mutex->queue.head;
                if (waiting != 0 && waiting->priority < priority)
                    priority = waiting->priority;
            }
            if (thread->priority == priority)
                break;
            thread = fn_801E087C(thread, priority);
        } while (thread != 0);
        if (lbl_805A06F4)
            fn_801E0A80(0);
    }
    OSRestoreInterrupts(enabled);
    return 1;
}