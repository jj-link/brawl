#include <types.h>
#include <revolution/OS/OSInterrupt.h>
#include <revolution/OS/OSMutex.h>
#include <revolution/OS/OSThread.h>
#pragma force_active on

OSThread* fn_801E0714(void);
s32 fn_801E0840(OSThread* self);
void fn_801E0760(void);
void fn_801E187C(OSThreadQueue* queue);
void fn_801E1790(OSThreadQueue* queue);

void fn_801DEE84(OSThreadQueue* arg0, OSMutex* arg1) {
    BOOL enabled;
    OSThread* currThread;
    OSMutex* next;
    OSMutex* prev;
    s32 savedCount;

    enabled = OSDisableInterrupts();
    currThread = fn_801E0714();

    if (arg1->thread == currThread) {
        next = arg1->next;
        savedCount = arg1->lock;
        prev = arg1->prev;
        arg1->lock = 0;

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

        arg1->thread = NULL;
        if (currThread->priority < currThread->base) {
            currThread->priority = fn_801E0840(currThread);
        }

        fn_801E0760();
        fn_801E187C(&arg1->queue);
        OSEnableScheduler();
        fn_801E1790(arg0);
        OSLockMutex(arg1);
        arg1->lock = savedCount;
    }

    OSRestoreInterrupts(enabled);
}
