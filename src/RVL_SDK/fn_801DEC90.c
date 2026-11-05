#include <types.h>
#include <revolution/OS/OSInterrupt.h>
#include <revolution/OS/OSMutex.h>
#include <revolution/OS/OSThread.h>
#pragma force_active on

OSThread* fn_801E0714(void);
s32 fn_801E0840(OSThread* self);
void fn_801E187C(OSThreadQueue* queue);

void OSUnlockMutex(OSMutex* mutex) {
    BOOL enabled = OSDisableInterrupts();
    OSThread* currThread = fn_801E0714();

    if (mutex->thread == currThread) {
        mutex->lock--;

        if (mutex->lock == 0) {
            OSMutex* next = mutex->next;
            OSMutex* prev = mutex->prev;

            if (next == NULL) {
                currThread->mutexQueue.tail = prev;
            } else {
                next->prev = prev;
            }

            if (prev == NULL) {
                currThread->mutexQueue.head = next;
            } else {
                prev->next = next;
            }

            mutex->thread = NULL;
            if (currThread->priority < currThread->base) {
                currThread->priority = fn_801E0840(currThread);
            }

            fn_801E187C(&mutex->queue);
        }
    }

    OSRestoreInterrupts(enabled);
}
