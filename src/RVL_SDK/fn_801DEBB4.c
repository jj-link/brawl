#include <revolution/OS/OSMutex.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

extern OSThread* fn_801E0714(void);
extern void fn_801E0A30(OSThread* thread, s32 priority);
extern void fn_801E1790(OSThreadQueue* queue);

void OSLockMutex(OSMutex* mutex) {
    BOOL enabled = OSDisableInterrupts();
    OSThread* currThread = fn_801E0714();

    while (TRUE) {
        if (mutex->thread == NULL) {
            OSMutex* tail;

            mutex->thread = currThread;
            mutex->lock++;

            tail = currThread->mutexQueue.tail;
            if (tail == NULL) {
                currThread->mutexQueue.head = mutex;
            } else {
                tail->next = mutex;
            }

            mutex->prev = tail;
            mutex->next = NULL;
            currThread->mutexQueue.tail = mutex;
            break;
        } else if (mutex->thread == currThread) {
            mutex->lock++;
            break;
        } else {
            currThread->mutex = mutex;
            fn_801E0A30(mutex->thread, currThread->priority);
            fn_801E1790(&mutex->queue);
            currThread->mutex = NULL;
        }
    }

    OSRestoreInterrupts(enabled);
}
